// Preprocessor directive:
// tells compiler to add contents of iostream header to program
#include <iostream>

// every program must have a main function
int main() {
  // << operator is the output operator
  // anything sent to std::cout via the output operator
  // should be printed on the screen
  std::cout << "Hello world!\n";

  // returning 0 means everything worked ok
  // non-zero numbers usually mean something went wrong
  // and program had to abort
  return 0;
}
