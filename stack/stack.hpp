#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include "../vector/vector.hpp"

namespace ft {

template<class T, class Container = ft::vector<T> >
class stack {
 public:

  typedef T value_type;

  typedef Container container_type;

  typedef typename container_type::size_type size_type;

  typedef typename container_type::reference reference;

  typedef typename container_type::const_reference const_reference;

  explicit stack(const container_type &cont = container_type()) : c(cont) {}

  stack(const stack &other) {
    *this = other;
  }

  stack &operator=(const stack &other) {
    this->c = other.c;
    return *this;
  }

  ~stack() {}

  reference top() {
    return c.back();
  }

  const_reference top() const {
    return c.back();
  }

  bool empty() const {
    return c.empty();
  }

  size_type size() const {
    return c.size();
  }

  void push(const value_type &value) {
    c.push_back(value);
  }

  void pop() {
    c.pop_back();
  }

 protected:
  container_type c;

 private:
  template<class Type, class Cont>
  friend bool operator==(const stack<Type, Cont> &lhs,
                         const stack<Type, Cont> &rhs);

  template<class Type, class Cont>
  friend bool operator!=(const stack<Type, Cont> &lhs,
                         const stack<Type, Cont> &rhs);

  template<class Type, class Cont>
  friend bool operator<(const stack<Type, Cont> &lhs,
                        const stack<Type, Cont> &rhs);

  template<class Type, class Cont>
  friend bool operator<=(const stack<Type, Cont> &lhs,
                         const stack<Type, Cont> &rhs);

  template<class Type, class Cont>
  friend bool operator>(const stack<Type, Cont> &lhs,
                        const stack<Type, Cont> &rhs);

  template<class Type, class Cont>
  friend bool operator>=(const stack<Type, Cont> &lhs,
                         const stack<Type, Cont> &rhs);
};

template<class T, class Container>
bool operator==(const ft::stack<T, Container> &lhs,
                const ft::stack<T, Container> &rhs) {
  return lhs.c == rhs.c;
}

template<class T, class Container>
bool operator!=(const ft::stack<T, Container> &lhs,
                const ft::stack<T, Container> &rhs) {
  return lhs.c != rhs.c;
}

template<class T, class Container>
bool operator<(const ft::stack<T, Container> &lhs,
               const ft::stack<T, Container> &rhs) {
  return lhs.c < rhs.c;
}

template<class T, class Container>
bool operator<=(const ft::stack<T, Container> &lhs,
                const ft::stack<T, Container> &rhs) {
  return lhs.c <= rhs.c;
}

template<class T, class Container>
bool operator>(const ft::stack<T, Container> &lhs,
               const ft::stack<T, Container> &rhs) {
  return lhs.c > rhs.c;
}

template<class T, class Container>
bool operator>=(const ft::stack<T, Container> &lhs,
                const ft::stack<T, Container> &rhs) {
  return lhs.c >= rhs.c;
}

}

#endif