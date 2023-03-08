#include <iostream>
#include "../vector/vectorTestes.hpp"

#if DEFAULT == 1

#include <vector>
namespace ft = std;

#else

#include "vector.hpp"
#endif


void testVectorSlowOperation() {
  std::cout << "Vector Slow Operation" << std::endl;

  ft::vector<int> myvector;

  for (int i = 0; i < 6000000; i++) {
    myvector.push_back(i);
  }

  for (int i = 0; i < 6000000; i++) {
    myvector[i] = i;
  }

  for (int i = 0; i < 6000000; i++) {
    myvector[i] = i;
  }
  myvector.clear();

  ft::vector<std::string> myvector2;

  for (int i = 0; i < 4000000; i++) {
    myvector2.push_back("test");
  }

  for (int i = 0; i < 4000000; i++) {
    myvector2[i] = "test";
  }

  for (int i = 0; i < 4000000; i++) {
    myvector2[i] = "test";
  }
}

void printIntVector(ft::vector<int> &vec) {
  std::cout << "Vector content: " ;
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " " ;
  }
  std::cout << std::endl;
}

void printCharVector(ft::vector<char> &vec) {
  std::cout << "Vector content: " ;
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " " ;
  }
  std::cout << std::endl;
}

void printStringVector(ft::vector<std::string> &vec) {
  std::cout << "Vector content: " ;
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " " ;
  }
  std::cout << std::endl;
}

void testVectorOperatorEqual() {
  std::cout << "\nTest operator= using 0 to 9"  << std::endl;

  ft::vector<int> vec1;
  ft::vector<int> vec2;

  for (int i = 0; i < 10; i++) {
    vec1.push_back(i);
  }

  vec2 = vec1;

  printIntVector(vec2);
}

void testAssignIntVector() {
  std::cout << "\nTest assign member function "  << std::endl;

  ft::vector<char> characters;

  std::cout << "Assigning 5 'a' characters to the vector"  << std::endl;
  characters.assign(5, 'a');
  printCharVector(characters);

  std::cout << "Assigning 3 'b' characters to the vector using iterator" 
            << std::endl;
  const std::string extra(6, 'b');
  characters.assign(extra.begin(), extra.end());
  printCharVector(characters);
}

void testVectorElementAccess() {
  std::cout << "\nTest element access"  << std::endl;

  ft::vector<int> vec;

  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
  }

  std::cout << "operator[]: "  << vec[0] << std::endl;
  std::cout << "at(): "  << vec.at(0) << std::endl;
  std::cout << "First element: "  << vec.front() << std::endl;
  std::cout << "Last element: "  << vec.back() << std::endl;
}

void testVectorIterators() {
  std::cout << "\nTest iterators"  << std::endl;

  ft::vector<int> vec;

  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
  }

  ft::vector<int>::iterator it = vec.begin();
  ft::vector<int>::iterator ite = vec.end();

  std::cout << "Vector content: " ;
  while (it != ite) {
    std::cout << *it << " " ;
    it++;
  }
  std::cout << std::endl;

  std::cout << "Reverse Iterator Test: "  << std::endl;

  ft::vector<int>::reverse_iterator rit = vec.rbegin();
  ft::vector<int>::reverse_iterator rite = vec.rend();

  std::cout << "Vector content: " ;
  while (rit != rite) {
    std::cout << *rit << " " ;
    rit++;
  }
  std::cout << std::endl;

}

void testVectorPushBack() {
  std::cout << "\nVector push_back test using 0 to 10"  << std::endl;

  ft::vector<int> ft_vector;

  for (int i = 0; i < 10; i++) {
    ft_vector.push_back(i);
  }

  printIntVector(ft_vector);
}

void testVectorPushBack10K() {
  std::cout << "\nVector push_back test using 0 to 10K"  << std::endl;

  ft::vector<int> ft_vector;

  for (int i = 0; i < 10000; i++) {
    ft_vector.push_back(i);
  }

  std::cout  << "Vector size: " << ft_vector.size()  << std::endl;
}

void testVectorSize() {
  std::cout << "\nVector size test using 0 to 42"  << std::endl;

  ft::vector<int> ft_vector;

  for (int i = 0; i < 42; i++) {
    ft_vector.push_back(i);
  }

  std::cout  << "Vector size: " << ft_vector.size()  << std::endl;
}

void testVectorResize() {
  std::cout << "\nVector resize test using 0 to 15"  << std::endl;

  ft::vector<int> ft_vector;

  for (int i = 0; i < 15; i++) {
    ft_vector.push_back(i);
  }

  std::cout  << "Vector before resize 10"  << std::endl;
  printIntVector(ft_vector);

  ft_vector.resize(10);

  std::cout  << "Vector after resize 10"  << std::endl;
  printIntVector(ft_vector);
}

void testVectorCapacity() {
  std::cout << "\nVector capacity test using 0 to 15"  << std::endl;

  ft::vector<int> ft_vector;

  for (int i = 0; i < 15; i++) {
    ft_vector.push_back(i);
  }

  std::cout  << "Vector size: " << ft_vector.size()  << std::endl;
  std::cout  << "Vector max_size: " << ft_vector.max_size()  << std::endl;
  std::cout  << "Vector capacity: " << ft_vector.capacity()  << std::endl;
  std::cout  << "Vector is empty: " << ft_vector.empty()  << std::endl;

  ft::vector<int> empty_vector;

  std::cout  << "\nEmpty vector size: " << empty_vector.size()  << std::endl;
  std::cout  << "Empty vector max_size: " << empty_vector.max_size()  << std::endl;
  std::cout  << "Empty vector capacity: " << empty_vector.capacity()  << std::endl;
  std::cout  << "Empty vector is empty: " << empty_vector.empty()  << std::endl;
}

void testVectorFillConstructor() {
  std::cout << "\nVector fill constructor test"  << std::endl;

  ft::vector<int> ft_vector(10, 42);

  printIntVector(ft_vector);
}

void testVectorClear() {
  std::cout << "\nVector clear test"  << std::endl;

  ft::vector<int> ft_vector;

  for (int i = 0; i < 10; i++) {
    ft_vector.push_back(i);
  }

  printIntVector(ft_vector);

  ft_vector.clear();

  std::cout  << "Vector size: " << ft_vector.size()  << std::endl;
  std::cout  << "Vector capacity: " << ft_vector.capacity()  << std::endl;
  std::cout  << "Vector is empty: " << ft_vector.empty()  << std::endl;

  std::cout  << "Content after clear: "  << std::endl;
  printIntVector(ft_vector); // Should be empty
}

void testVectorInsert() {
  std::cout << "\nVector insert test"  << std::endl;

  ft::vector<int> ft_vector;

  for (int i = 0; i < 10; i++) {
    ft_vector.push_back(i);
  }

  printIntVector(ft_vector);

  ft_vector.insert(ft_vector.begin(), 42);

  std::cout  << "Vector after insert 42 at begin"  << std::endl;
  printIntVector(ft_vector);

  ft_vector.insert(ft_vector.end(), 42);

  std::cout  << "Vector after insert 42 at end"  << std::endl;
  printIntVector(ft_vector);

  ft_vector.insert(ft_vector.begin() + 5, 42);

  std::cout  << "Vector after insert 42 at begin + 5"  << std::endl;
  printIntVector(ft_vector);

  ft_vector.insert(ft_vector.begin() + 5, 3, 42);

  std::cout  << "Vector after insert 3 * 42 at begin + 5"  << std::endl;
  printIntVector(ft_vector);
}

void testVectorErase() {
  std::cout << "\nVector erase test"  << std::endl;

  ft::vector<int> ft_vector;

  for (int i = 0; i < 10; i++) {
    ft_vector.push_back(i);
  }

  printIntVector(ft_vector);

  ft_vector.erase(ft_vector.begin());

  std::cout  << "Vector after erase at begin"  << std::endl;
  printIntVector(ft_vector);
}

void testVectorPopBack() {
  std::cout << "\nVector pop_back test"  << std::endl;

  ft::vector<int> ft_vector;

  for (int i = 0; i < 10; i++) {
    ft_vector.push_back(i);
  }

  printIntVector(ft_vector);

  ft_vector.pop_back();

  std::cout  << "Vector after pop_back"  << std::endl;
  printIntVector(ft_vector);
}

void testVectorSwap() {
  std::cout << "\nVector swap test"  << std::endl;

  ft::vector<std::string> ft_vector1;
  ft::vector<std::string> ft_vector2;

  ft_vector1.push_back("Hello");
  ft_vector1.push_back("World");
  ft_vector1.push_back("!");

  ft_vector2.push_back("Ola");
  ft_vector2.push_back("Mundo");
  ft_vector2.push_back("!");

  std::cout  << "Vector 1 before swap:\t" ;
  printStringVector(ft_vector1);

  std::cout  << "Vector 2 before swap:\t" ;
  printStringVector(ft_vector2);

  ft_vector1.swap(ft_vector2);

  std::cout  << "\nVector 1 after swap:\t" ;
  printStringVector(ft_vector1);

  std::cout  << "Vector 2 after swap:\t" ;
  printStringVector(ft_vector2);
}

void testComparesEqual(const ft::vector<int> &vector1, const ft::vector<int> &vector2) {
  std::cout  << "\noperator== test"  << std::endl;
  std::cout 
            << "ft_vector1 == ft_vector2: "
            
            << (vector1 == vector2)
            << std::endl;
}

void testComparesNotEqual(const ft::vector<int> &vector1, const ft::vector<int> &vector2) {
  std::cout  << "\noperator!= test"  << std::endl;
  std::cout 
            << "ft_vector1 != ft_vector2: "
            
            << (vector1 != vector2)
            << std::endl;
}

void testComparesLess(const ft::vector<int> &vector1, const ft::vector<int> &vector2) {
  std::cout  << "\noperator< test"  << std::endl;
  std::cout 
            << "ft_vector1 < ft_vector2: "
            
            << (vector1 < vector2)
            << std::endl;
}

void testComparesLessEqual(const ft::vector<int> &vector1, const ft::vector<int> &vector2) {
  std::cout  << "\noperator<= test"  << std::endl;
  std::cout 
            << "ft_vector1 <= ft_vector2: "
            
            << (vector1 <= vector2)
            << std::endl;
}

void testComparesGreater(const ft::vector<int> &vector1, const ft::vector<int> &vector2) {
  std::cout  << "\noperator> test"  << std::endl;
  std::cout 
            << "ft_vector1 > ft_vector2: "
            
            << (vector1 > vector2)
            << std::endl;
}

void testComparesGreaterEqual(const ft::vector<int> &vector1, const ft::vector<int> &vector2) {
  std::cout  << "\noperator>= test"  << std::endl;
  std::cout 
            << "ft_vector1 >= ft_vector2: "
            
            << (vector1 >= vector2)
            << std::endl;
}

void testVectorCompares() {
  std::cout << "\n" << "Vector compares test"  << std::endl;
  ft::vector<int> ft_vector1;
  ft::vector<int> ft_vector2;

  for (int i = 0; i < 10; i++) {
    ft_vector1.push_back(i);
    ft_vector2.push_back(i + 1);
  }

  testComparesEqual(ft_vector1, ft_vector2);
  testComparesNotEqual(ft_vector1, ft_vector2);
  testComparesLess(ft_vector1, ft_vector2);
  testComparesLessEqual(ft_vector1, ft_vector2);
  testComparesGreater(ft_vector1, ft_vector2);
  testComparesGreaterEqual(ft_vector1, ft_vector2);
}

void vectorTestes () {
  testVectorSlowOperation();
  testVectorOperatorEqual();
  testAssignIntVector();
  testVectorElementAccess();
  testVectorIterators();
  testVectorPushBack();
  testVectorPushBack10K();
  testVectorSize();
  testVectorResize();
  testVectorCapacity();
  testVectorFillConstructor();
  testVectorInsert();
  testVectorErase();
  testVectorPopBack();
  testVectorSwap();
  testVectorCompares();
  testVectorClear();
}
