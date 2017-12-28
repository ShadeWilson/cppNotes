//Write a function called doubleNumber() that takes one integer parameter and 
//returns twice the value passed in.

#include <iostream>

int doubleNumber(int a) {
  return a + a;
}

int main() {
  int a;
  std::cout << "Enter a number to double: ";
  std::cin >> a;
  
  std::cout << doubleNumber(a) << std::endl;
  return 0;
}


