#include <iostream>
#include "../includes/stack/stackTestes.hpp"

#if DEFAULT == 1

#include <stack>

namespace ft = std;

#else

#include "../includes/stack/stack.hpp"

#endif

void testsStackSlowOperation() {
  std::cout << "Tests Stack Slow Operation" << std::endl;
  std::cout << "\t-----\t-----\t-----\t" << std::endl;
  ft::stack<int> stack;

  for (int i = 0; i < 8000000; i++) {
    stack.push(i);
  }
  std::cout << stack.size() << " elements on stack\n";

  for (int i = 0; i < 8000000; i++) {
    stack.pop();
  }
  std::cout << stack.size() << " elements on stack\n";

  for (int i = 0; i < 8000000; i++) {
    stack.push(i);
  }
  std::cout << stack.size() << " elements on stack\n";
  std::cout << "Top element: " << stack.top() << '\n';

  for (int i = 0; i < 1000000; i++) {
    stack.pop();
  }
  std::cout << stack.size() << " elements on stack\n";

  std::cout << "\t-----\t-----\t-----\t" << std::endl;
  ft::stack<std::string> stack2;

  for (int i = 0; i < 1000000; i++) {
    stack2.push("Anderson");
  }
  std::cout << stack.size() << " elements on stack\n";
  std::cout << "Top element: " << stack2.top() << '\n';

  for (int i = 0; i < 1000000; i++) {
    stack2.pop();
  }
  std::cout << stack.size() << " elements on stack\n";
}

void testCopyUsingEqual() {
  std::cout << "Tests Copy Using Equal" << std::endl;
  std::cout << "\t-----\t-----\t-----\t" << std::endl;
  ft::stack<int> stack;
  ft::stack<int> stack2;

  for (int i = 0; i < 10; i++) {
    stack.push(i);
  }
  stack2 = stack;
  std::cout << "Stack 1: ";
  while (!stack.empty()) {
    std::cout << stack.top() << " ";
    stack.pop();
  }
  std::cout << std::endl;
  std::cout << "Stack 2: ";
  while (!stack2.empty()) {
    std::cout << stack2.top() << " ";
    stack2.pop();
  }
  std::cout << std::endl;
  std::cout << "\t-----\t-----\t-----\t" << std::endl;
}

void testsCapacity() {
  std::cout << "Tests Capacity" << std::endl;
  std::cout << "\t-----\t-----\t-----\t" << std::endl;
  ft::stack<int> stack;

  std::cout << "Empty: " << stack.empty() << std::endl;
  std::cout << "Size: " << stack.size() << std::endl;
  for (int i = 0; i < 10; i++) {
    stack.push(i);
  }
  std::cout << "Empty: " << stack.empty() << std::endl;
  std::cout << "Size: " << stack.size() << std::endl;
  std::cout << "\t-----\t-----\t-----\t" << std::endl;
}

void testsPush() {
  std::cout << "Tests Push" << std::endl;
  std::cout << "\t-----\t-----\t-----\t" << std::endl;
  ft::stack<int> stack;

  for (int i = 0; i < 10; i++) {
    stack.push(i);
  }
  std::cout << "Stack: ";
  while (!stack.empty()) {
    std::cout << stack.top() << " ";
    stack.pop();
  }
  std::cout << std::endl;
  std::cout << "\t-----\t-----\t-----\t" << std::endl;
}

void testsPop() {
  std::cout << "Tests Pop" << std::endl;
  std::cout << "\t-----\t-----\t-----\t" << std::endl;
  ft::stack<int> stack;

  for (int i = 0; i < 10; i++) {
    stack.push(i);
  }
  std::cout << "Stack: ";
  while (!stack.empty()) {
    std::cout << stack.top() << " ";
    stack.pop();
  }
  std::cout << std::endl;
  std::cout << "\t-----\t-----\t-----\t" << std::endl;
}

void testsNoMemberFunctions() {
  std::cout << "Tests No Member Functions" << std::endl;
  std::cout << "\t-----\t-----\t-----\t" << std::endl;
  ft::stack<int> stack;
  ft::stack<int> stack2;

  for (int i = 0; i < 10; i++) {
    stack.push(i);
  }

  std::cout << "Operator== 1 stack with 10 elements and another empty" << std::endl;
  std::cout << (stack == stack2) << std::endl;

  std::cout << "Operator!= 1 stack with 10 elements and another empty" << std::endl;
  std::cout << (stack != stack2) << std::endl;

  std::cout << "Operator< 1 stack with 10 elements and another empty" << std::endl;
  std::cout << (stack < stack2) << std::endl;

  std::cout << "Operator<= 1 stack with 10 elements and another empty" << std::endl;
  std::cout << (stack <= stack2) << std::endl;

  std::cout << "Operator> 1 stack with 10 elements and another empty" << std::endl;
  std::cout << (stack > stack2) << std::endl;

  std::cout << "Operator>= 1 stack with 10 elements and another empty" << std::endl;
  std::cout << (stack >= stack2) << std::endl;

  std::cout << "\t-----\t-----\t-----\t" << std::endl;
  std::cout << std::endl;
  std::cout << "\t-----\t-----\t-----\t" << std::endl;
}

void stackTestes() {
  testsStackSlowOperation();
  testCopyUsingEqual();
  testsCapacity();
  testsPush();
  testsPop();
}