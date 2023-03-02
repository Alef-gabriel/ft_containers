#include "map.hpp"
#include "Tree.hpp"
#include <chrono>
#include <map>


int main() {
    ft::map<int, int> newmap;
    std::map<int, int> myMap;

    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 1; i < 10; i++) {
        myMap.insert({i, i});
    }
    int value = 0;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Value : " << value << " " << "Execution time: " << duration.count() << " microseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for(int i = 1; i < 3000; i++) {
        newmap.insert(i, i);
    }
    value = newmap.find(452);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Value : " << value << " " << "Execution time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}