#include <iostream>
#include "Hash.hpp"
#include <cstdlib>
#include <ctime>

int main() {

  srand(time(0));

  Hash h(30);

  for (int i = 0; i < 15; ++i) {
    std::cout << h.insert(rand() % 3) << std::endl;
  }

  h.display();

}
