#ifndef VECTORTESTES_HPP
#define VECTORTESTES_HPP
#include "vector.hpp"

void testVectorSlowOperation();

void printIntVector(ft::vector<int> &vec);

void printCharVector(ft::vector<char> &vec);

void printStringVector(ft::vector<std::string> &vec);

void testVectorOperatorEqual();

void testAssignIntVector();

void testVectorElementAccess();

void testVectorIterators();

void testVectorPushBack();

void testVectorPushBack10K();

void testVectorSize();

void testVectorResize();

void testVectorCapacity();

void testVectorFillConstructor();
void testVectorClear();

void testVectorInsert();

void testVectorErase();

void testVectorPopBack();

void testVectorSwap();

void testComparesEqual(const ft::vector<int> &vector1, const ft::vector<int> &vector2);

void testComparesNotEqual(const ft::vector<int> &vector1, const ft::vector<int> &vector2);

void testComparesLess(const ft::vector<int> &vector1, const ft::vector<int> &vector2);

void testComparesLessEqual(const ft::vector<int> &vector1, const ft::vector<int> &vector2);

void testComparesGreater(const ft::vector<int> &vector1, const ft::vector<int> &vector2);

void testComparesGreaterEqual(const ft::vector<int> &vector1, const ft::vector<int> &vector2);

void testVectorCompares();

void vectorTestes();

#endif