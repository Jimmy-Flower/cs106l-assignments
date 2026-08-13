#include<string>

class Baby
{
private:
	std::string name;
	std::string gender;
	int age;
	double weight; //kg
	bool is_hungry;
	void digestFood();

public:
	Baby(std::string name, std::string gender, int age, double weight, bool is_hungry);
	std::string getName() const;
	std::string getGender() const;
	int getAge() const;
	double getWeight() const;
	bool getIsHungry() const;
	
	void setName(std::string name);
	void setGender(std::string gender);
	void setAge(int age);
	void setIsHungry(bool is_hungry);
	
	void eat();
};