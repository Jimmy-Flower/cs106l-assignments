#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>
#include <cctype>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  // step1: Identify all iterators to space characters
  std::vector<std::string::iterator> spaces;
  spaces = find_all(source.begin(), source.end(), [](const auto& cur){ return std::isspace(cur); });
  
  // step2: Generate tokens between consecutive space characters
  Corpus tokens;
  std::transform(spaces.begin(), spaces.end() - 1, spaces.begin() + 1, std::inserter(tokens, tokens.end()),[&source](const auto& begin, const auto& end){
    return Token(source, begin, end);
  });
  
  // Step 3: Get rid of empty tokens
  std::erase_if(tokens, [](const auto& it){ return it.content.empty(); });
  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  
  namespace rv = std::ranges::views;
  auto view = source // Token
	| rv::filter([&dictionary](const auto& token){ return !dictionary.contains(token.content); }) // (Wrong) Token
	| rv::transform([&dictionary](const auto& token){
		// (Wrong) Token -> Misspelling
		auto res = dictionary | rv::filter([&token](const auto& str){
			return levenshtein(token.content, str) == 1;
		});
		std::set<std::string> suggestions(res.begin(), res.end());
		return Misspelling{token, suggestions};
	});

  auto view2 = view | rv::filter([](const auto& misspelling){ return !misspelling.suggestions.empty(); });
  //return view;
  return std::set<Misspelling>(view2.begin(), view2.end());
};

/* Helper methods */

#include "utils.cpp"