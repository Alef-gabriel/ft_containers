#include "map.hpp"
#include <chrono>
#include <map>


int main() {
    ft::map newmap;
    std::map<int, int> myMap;

    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 3000; i > 1; i--) {
        myMap.insert({i, i});
    }
    int value = myMap[1000];
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Value : " << value << " " << "Execution time: " << duration.count() << " microseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for(int i = 1; i < 9; i++) {
        newmap.insert(i);
    }
    value = newmap.search(2);
    newmap.remove(7);
    value = newmap.search(7);
    newmap.remove(4);
    value = newmap.search(4);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Value : " << value << " " << "Execution time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}