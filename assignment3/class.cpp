#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "class.h"

Baby::Baby(std::string name, std::string gender, int age, double weight, bool is_hungry) : 
name{name}, gender{gender}, age{age}, weight{weight}, is_hungry{is_hungry} {}

std::string Baby::getName() const { return name; }

std::string Baby::getGender() const { return gender; }

int Baby::getAge() const { return age; }

double Baby::getWeight() const { return age;	}

bool Baby::getIsHungry() const { return is_hungry; }

void Baby::setName(std::string name) { this->name = name; }

void Baby::setGender(std::string gender)
{
	if(gender != "male" && gender != "female") return;
	this->gender = gender;
}

void Baby::setAge(int age)
{
	if(age <= 0) return;
	this->age = age;
}

void Baby::setIsHungry(bool is_hungry) { this->is_hungry = is_hungry; }

void Baby::eat()
{
	if(!is_hungry) return;
	digestFood();
}

void Baby::digestFood()
{
	weight += 0.1;
	is_hungry = false;
}