#include <iostream>

int main() {

  // uninitialized variable!
  int x;

  std::cout << x;

  return 0;
}

// Example outputs: Garbage!
// 177893430
// 54624310
// 210325558
