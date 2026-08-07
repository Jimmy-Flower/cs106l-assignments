/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "Jimmy Flower"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::set<std::string> name;
  
  std::ifstream ifs(filename);
  
  std::string line;
  while(std::getline(ifs, line))
  {
	name.insert(line);
  }
  
  return name;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> names;
  
  for(const auto& it : students) //注意这里一定要&，否则只是一个复制，函数结束后会变成悬空指针
  {
	int pos = -1;
	for(int i = 0 ; i < it.size(); i++) if(it[i] == ' ') pos = i;
	if(it[0] == name[0] && it[pos + 1] == name[6]) names.push(&it);
  }
  return names;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  std::string answer = "NO MATCHES FOUND";
 
  while(!matches.empty())
  {
	std::string name = *(matches.front());
	matches.pop();
	if((name.size() >= 5 && name.size() <= 13) || matches.empty())
	{
		answer = name;
		break;
	}
  }
  
  return answer;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"