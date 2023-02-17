#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include "vector.hpp"

// int main() {
//     ft::Vector<int> bg;
//     std::vector<int> tt;
//     printf("hello");
//     bg.push_back(5);
//     //bg.pop_back();
//     bg.push_back(8);
//     bg.at(1) = 20;
//     std::cout << bg[0] << " " << bg[1] << " " << bg[2] << '\n';
//     return 0;
// }

void reserve()
{
    ft::vector<int> myVec;
    std::vector<int> defaultVec;
    myVec.push_back(5);
    myVec.push_back(8);

    defaultVec.push_back(5);
    defaultVec.push_back(8);

    std::cout << sizeof(defaultVec) << " " << sizeof(myVec) << '\n';
    std::cout << "Default vector capacity: " << defaultVec.capacity() << " Default vector size: " << defaultVec.size() << '\n';
    std::cout << "my vector capacity: " << myVec.capacity() << " my vector size: " << myVec.size() << '\n';
    defaultVec.reserve(120);
    myVec.reserve(120);
    std::cout << "\n******** AFTER OF RESERVE ********" << '\n';
    std::cout << "Default vector capacity: " << defaultVec.capacity() << " Default vector size: " << defaultVec.size() << '\n';
    std::cout << "my vector capacity: " << myVec.capacity() << " my vector size: " << myVec.size() << '\n';
}

void shrink_to_fit()
{
    ft::vector<int> myVec;
    std::vector<int> defaultVec;
    myVec.push_back(5);
    myVec.push_back(8);

    defaultVec.push_back(5);
    defaultVec.push_back(8);

    defaultVec.reserve(120);
    myVec.reserve(120);
    std::cout << "Default vector capacity: " << defaultVec.capacity() << " Default vector size: " << defaultVec.size() << '\n';
    std::cout << "my vector capacity: " << myVec.capacity() << " my vector size: " << myVec.size() << '\n';

    defaultVec.shrink_to_fit();
    myVec.shrink_to_fit();
    std::cout << "\n******** AFTER OF SHRINK_TO_FIT ********" << '\n';
    std::cout << "Default vector capacity: " << defaultVec.capacity() << " Default vector size: " << defaultVec.size() << '\n';
    std::cout << "my vector capacity: " << myVec.capacity() << " my vector size: " << myVec.size() << '\n';
}

void inserte()
{
    ft::vector<int> myVec;
    std::vector<int> defaultVec;

    myVec.push_back(5);
    myVec.push_back(8);
    defaultVec.push_back(5);
    defaultVec.push_back(8);
    // using begin() to print vector
    myVec.insert(myVec.begin() + 6, 33);
    defaultVec.insert(defaultVec.begin() + 6, 33);
    std::cout << "\n******** ALL ELEMENTES IN MY VECTOR ********" << '\n';
    for (auto it = myVec.begin();
         it != myVec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "\n******** ALL ELEMENTES IN DEFAULT VECTOR ********" << '\n';
    for (auto it = defaultVec.begin();
         it != defaultVec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Default vector capacity: " << defaultVec.capacity() << " Default vector size: " << defaultVec.size() << '\n';
    std::cout << "my vector capacity: " << myVec.capacity() << " my vector size: " << myVec.size() << '\n';

    std::cout << defaultVec[6] << '\n';
    std::cout << myVec[6] << '\n';
}

void pop_back() {
    ft::vector<int> myVec;
    std::vector<int> defaultVec;
    myVec.push_back(5);
    myVec.push_back(8);
    defaultVec.push_back(5);
    defaultVec.push_back(8);
    defaultVec.pop_back();
    myVec.pop_back();

    std::cout << "Default vector capacity: " << defaultVec.capacity() << " Default vector size: " << defaultVec.size() << '\n';
    std::cout << "my vector capacity: " << myVec.capacity() << " my vector size: " << myVec.size() << '\n';
    std::cout << defaultVec[1] << '\n';
    std::cout << myVec[1] << '\n';
}

void erase() {
    ft::vector<int> myVec;
    std::vector<int> defaultVec;
    myVec.push_back(5);
    myVec.push_back(8);
    myVec.push_back(15);
    myVec.push_back(18);
    defaultVec.push_back(5);
    defaultVec.push_back(8);
    defaultVec.push_back(15);
    defaultVec.push_back(18);
    
    defaultVec.erase(defaultVec.begin() + 1);
    myVec.erase(myVec.begin() + 1);
    std::cout << "Default vector capacity: " << defaultVec.capacity() << " Default vector size: " << defaultVec.size() << '\n';
    std::cout << "my vector capacity: " << myVec.capacity() << " my vector size: " << myVec.size() << '\n';

    for (auto it = myVec.begin();
         it != myVec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    for (auto it = defaultVec.begin();
         it != defaultVec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void resize() {
    ft::vector<int> myVec;
    std::vector<int> defaultVec;
    myVec.push_back(5);
    myVec.push_back(8);
    myVec.push_back(15);
    myVec.push_back(18);
    defaultVec.push_back(5);
    defaultVec.push_back(8);
    defaultVec.push_back(15);
    defaultVec.push_back(18);
    // using begin() to print vector
    
    defaultVec.resize(1);
    myVec.resize(1);
    std::cout << "Default vector capacity: " << defaultVec.capacity() << " Default vector size: " << defaultVec.size() << '\n';
    std::cout << "my vector capacity: " << myVec.capacity() << " my vector size: " << myVec.size() << '\n';

    for (auto it = myVec.begin();
         it != myVec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    for (auto it = defaultVec.begin();
         it != defaultVec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

int main()
{
    // declaration of vector container
    ft::vector<int> myVec = {1, 1, 3};
    ft::vector<int> defaultVec{4, 5 , 6};
    // myVec.push_back(5);
    // myVec.push_back(8);
    // myVec.push_back(15);
    // myVec.push_back(18);
    // defaultVec.push_back(5);
    // defaultVec.push_back(8);
    // defaultVec.push_back(15);
    // defaultVec.push_back(18);
    // using begin() to print vector
    
    if (myVec == defaultVec)
        std::cout << "flase" << '\n';
    // std::cout << "Default vector capacity: " << defaultVec.capacity() << " Default vector size: " << defaultVec.size() << '\n';
    // std::cout << "my vector capacity: " << myVec.capacity() << " my vector size: " << myVec.size() << '\n';

    // for (auto it = myVec.begin();
    //      it != myVec.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    // for (auto it = defaultVec.begin();
    //      it != defaultVec.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    return 0;
}