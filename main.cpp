#include "map.hpp"
#include <chrono>
#include <map>


int main() {
    ft::map newmap;
    std::map<int, int> myMap;

    for(int i = 1; i < 300; i++) {
        myMap.insert({i, i});
    }
    auto start = std::chrono::high_resolution_clock::now();
    int value = myMap[299];
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Value : " << value << " " << "Execution time: " << duration.count() << " microseconds" << std::endl;

    for(int i = 1; i < 9; i++) {
        newmap.insert(i);
    }
    start = std::chrono::high_resolution_clock::now();
    // node *tt = search(tree, 299);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // std::cout << "Value : " << tt->value << " " << "Execution time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}