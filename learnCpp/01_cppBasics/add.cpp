#include <iostream>

int add(int a, int b) {
  int sum = a + b;
  return sum;
}

int main() {
  int a;
  int b;
  
  std::cout << "Enter an int: ";
  std::cin >> a; 
  
  std::cout << "Enter another int: ";
  std::cin >> b;
  
  std::cout << add(a, b) << std::endl;
  std::cout << add(a, add(a, b)) << std::endl; // calling functions within functions
  
  return 0;
}


