#include "map.hpp"
#include <map>


int main() {
    ft::map<int, int> newmap;
    std::map<int, int> myMap;

    for(int i = 1; i < 10; i++) {
        myMap.insert(std::pair<int, int>(i, i));
    }
    for(int i = 1; i < 3000; i++) {
        newmap.insert(ft::pair<int, int>(i, i));
    }
    return 0;
}