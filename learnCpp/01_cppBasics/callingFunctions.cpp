#include <iostream>

// Definition of function
void doPrint() {
  std::cout << "In doPrint()" << std::endl;
}

int main() {
  std::cout << "Starting main()" << std::endl;

  doPrint();

  std::cout << "Ending main()" <<std::endl;

  return 0;
}
