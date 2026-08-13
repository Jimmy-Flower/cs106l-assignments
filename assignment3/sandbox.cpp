/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

 #include "class.h"
 
void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  Baby baby{"Coke", "male", 3, 9.5, true};
  
  std::cout << baby.getName() << std::endl;
  
  std::cout << baby.getGender() << std::endl;
  
  std::cout << baby.getAge() << std::endl;
  
  std::cout << baby.getWeight() << std::endl;
  
  std::cout << baby.getIsHungry() << std::endl;
  
  baby.setName("ShaoYu");
  
  std::cout << baby.getName() << std::endl;
  
  baby.eat();
  
  std::cout << baby.getIsHungry() << std::endl;
  
  std::cout << baby.getWeight() << std::endl;
}