#include <iostream>
#include <string>

int main() {
  
  std::cout << "What is your name? ";
  
  std::string name;
  std::cin >> name;
  
  std::string greeting = "Hello, " + name + "!";
  std::string spaces(greeting.size(), ' ');
  std::string middle = "* " + spaces + " *";
  
  std::string border(middle.size(), '*'); 
  
  
  std::cout << border << std::endl;
  std::cout << middle << std::endl;
  std::cout << "* " + greeting + " *" << std::endl;
  std::cout << middle << std::endl;
  std::cout << border << std::endl;

  
  
  return 0;
}














