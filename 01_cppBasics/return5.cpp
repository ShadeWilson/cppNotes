#include <iostream>

int return5() {
  return 5;
}

int main() {

  std::cout << return5() << std::endl;
  std::cout << return5() + 2 << std::endl;

  // the value of 5 is returned but it ignored since we dont do anything w/ it
  return5();

  return 0;
}
