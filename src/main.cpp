#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <map>

#include "../includes/map/mapTestes.hpp"
#include "../includes/vector/vectorTestes.hpp"
#include "../includes/stack/stackTestes.hpp"
#include "../includes/map/map.hpp"

void testSelector(int number, const char *argv[]);


int main(int argc, const char *argv[]) {
    std::clock_t start = std::clock();

    testSelector(argc, argv);

    std::clock_t end = std::clock();
    double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Elapsed time: " << elapsed << " seconds." << std::endl;
    return 0;
}

void errorAndExit() {
  std::cout << "Tests: -m (Map), -v (Vector), -s (Stack)" << std::endl;
  exit(1);
}

void testSelector(int number, const char *argv[]) {
  if (number != 2) {
    errorAndExit();
  }

  if (strcmp(argv[1], "-m") == 0) {
    std::cout << "Map Test" << std::endl;
    mapTestes();
  } else if (strcmp(argv[1], "-v") == 0) {
    std::cout << "Vector Test" << std::endl;
    vectorTestes();
  } else if (strcmp(argv[1], "-s") == 0) {
    std::cout << "Stack Test" << std::endl;
    stackTestes();
  } else {
    errorAndExit();
  }
}
