#ifndef TYPES_HPP
#define TYPES_HPP

namespace ft {

template<class T, T v>
struct integral_constant {
  typedef T value_type;

  typedef integral_constant<T, v> type;

  static const T value = v;

  operator T() const { return value; }
};

template<class T>
struct is_integral : public integral_constant<bool, false> {};

template<>
struct is_integral<bool> : public integral_constant<bool, true> {};

template<>
struct is_integral<char> : public integral_constant<bool, true> {};

template<>
struct is_integral<signed char> : public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned char> : public integral_constant<bool, true> {};

template<>
struct is_integral<wchar_t> : public integral_constant<bool, true> {};

template<>
struct is_integral<short> : public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned short> : public integral_constant<bool, true> {};

template<>
struct is_integral<int> : public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned int> : public integral_constant<bool, true> {};

template<>
struct is_integral<long> : public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned long> : public integral_constant<bool, true> {};

template<>
struct is_integral<long long> : public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned long long> : public integral_constant<bool, true> {};

template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> {
  typedef T type;
};

}
#endif