#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "VectorIterator.hpp"
#include "../ReverseIterator.hpp"
#include "../types.hpp"
#include "../auxiliary.hpp"

namespace ft {
template<class T, class Allocator = std::allocator<T> >
class vector
{
public:
	typedef Allocator 		allocator_type;
	typedef T	value_type;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
  	typedef typename allocator_type::pointer pointer;
  	typedef typename allocator_type::const_pointer const_pointer;
	typedef ft::VectorIterator<value_type> iterator;
	typedef ft::VectorIterator<const value_type> const_iterator;
	typedef ft::ReverseIterator<iterator> reverse_iterator;
	typedef ft::ReverseIterator<const_iterator> const_reverse_iterator;

	vector() : m_size(0), m_capacity(0), m_data(NULL) {}

	explicit vector (const allocator_type &alloc): _allocator(alloc), m_size(0), m_capacity(0), m_data(NULL) {}

	vector (vector const & obj){
		*this = obj;
	}

	explicit vector (size_type count,
					const value_type &value = value_type(),
					const allocator_type &alloc = allocator_type()) {
		m_size =  count;
		m_capacity = count;
		_allocator = alloc;
		m_data =  _allocator.allocate(count);
		for (size_type i = 0; i < count; i++) {
			_allocator.construct(m_data, value);
		}
	}

	void assign(size_type count, const value_type &value) {
		m_size = 0;
		reserve(count);
		for (size_type i = 0; i < count; i++)
		push_back(value);
	}

	template<class Interator>
	void assign(Interator first,
				Interator last,
				typename ft::enable_if<!ft::is_integral<Interator>::value,
										Interator>::type = Interator()) {
		clear();
		reserve(last - first);
		while (first != last)
			push_back(*first++);
	}

	vector& operator=( vector&& obj ) {
		this->_allocator = obj.get_allocator();
		this->m_size = obj.size();
		this->m_capacity = obj.capacity();
		this->m_data = this->data();
		*this = obj;
		return *this;
	}

	~vector(void){
		delete[] m_data;
	}

	value_type & operator[](int i){
		return m_data[i];
	}

	iterator begin(){
		return iterator(m_data);
	}

	iterator end(){
		return iterator(m_data + m_size);
	}

	reference & at(size_type pos){
		if (pos >= this->size())
      		throw (std::out_of_range("ft::vector::out-of-range"));
    	return (m_data[pos]);
	}
	
	const_reference at(size_type pos) const {
		if (pos >= this->size())
			throw (std::out_of_range("ft::vector::out-of-range"));
		return (m_data[pos]);
  	}

	value_type *data(){
		return m_data;
	}

	const value_type *data() const {
    	return m_data;
  	}

	reference & front(void){
		return m_data[0];
	}

	const_reference front() const {
    	return (m_data[0]);
	}

	reference & back(void){
		return m_data[m_size - 1];
	}

	const_reference back() const {
    return (m_data[m_size - 1]);
	}

	reverse_iterator rbegin(void){
		return reverse_iterator(end());
	}

	const_reverse_iterator rbegin() const {
    	return const_reverse_iterator(end());
  	}

	reverse_iterator rend() {
   		return reverse_iterator(begin());
  	}

	const_reverse_iterator rend() const {
    	return const_reverse_iterator(begin());
  	}

	bool empty(void) const {
		if (m_size == 0)
			return true;
		return false;
	}

	size_type size() const{
		return m_size;
	}

	size_type max_size() const{
		return _allocator.max_size();
	}

	void push_back(value_type data){
		size_type	newCapacity;

		newCapacity = m_capacity + 1;
		if (m_capacity <= m_size)
			reserve(newCapacity);
		m_size++;
		m_data[m_size - 1] = data;
	}

	void pop_back() {
		if (m_size > 0) {
			_allocator.destroy(m_data + m_size);
			m_size--;
		}
	}

	size_type size(void){
		return m_size;
	}

	bool empty(void){
		if (m_size > 0)
			return false;
		return true;
	}

	size_type capacity() const {
		return m_capacity;
	}

	void reserve( size_type new_cap ) {
		if (new_cap > max_size())
      		throw std::length_error("ft::vector::length_error");
		value_type* newBlock = _allocator.allocate(new_cap);
		for (size_type i = 0; i < m_size; i++)
			newBlock[i] = m_data[i];
		_allocator.deallocate(m_data, m_size);
		m_data = newBlock;
		m_capacity = new_cap;
	}

	allocator_type get_allocator() const{
		return _allocator;
	}

	void shrink_to_fit(void) {
		reserve(m_size);
	}

	void clear() {
		_allocator.deallocate(m_data, m_size);
		m_size = 0;
	}

	iterator insert( iterator pos, const value_type & value ) {
		size_type index = std::distance( this->begin(), pos);
		if (index > this->max_size())
			return pos;
		if (index > m_size) {
			this->reserve(index - m_size);
			m_data[index] = value;
			m_size++;
		}
		else {
			value_type var;
			value_type aux = value;
			this->reserve(m_size + 2);
			for (size_type i = index; i < (m_size + 1); i++) {
				var = m_data[i];
				m_data[i] = aux;
				aux = var;
			}
			m_size++;
		}
		return pos;
	}

	void insert(iterator pos, size_type count, const value_type &value) {
		vector tmp;
		size_type index = pos - begin();
		size_type tmp_end = end() - pos;

		tmp.assign(pos, end());
		if ((count + m_capacity) > (m_capacity * 2)) {
			reserve(m_size + count);
		}
		else if (!m_size) {
			reserve(count);
		}
		m_size = index;
		for (size_type i = 0; i < count; i++) {
			push_back(value);
		}
		for (size_type i = 0; i < tmp_end; i++) {
			push_back(tmp[i]);
		}
 	}

	template<class Interator>
	void insert(iterator pos,
				Interator first,
				Interator last,
				typename ft::enable_if<!ft::is_integral<Interator>::value,
										Interator>::type = Interator()) {
		vector tmp;
		size_type index = pos - begin();
		size_type tmp_end = end() - pos;
		difference_type diference = last - first;

		tmp.assign(pos, end());
		if ((diference + m_capacity) > (m_capacity * 2)) {
			reserve(m_size + diference);
		}
		else if (!m_size) {
			reserve(diference);
		}
		m_size = index;
		do {
			push_back(*first++);
		} while (first != last);
		for (size_type i = 0; i < tmp_end; i++) {
			push_back(tmp[i]);
		}
  	}

	iterator erase( iterator pos ) {
		size_type index = std::distance( this->begin(), pos);
		if (index > m_size) {
			return pos;
		}
		value_type var;
		_allocator.destroy(m_data + index);
		for (size_type i = index; i < m_size; i++) {
			if ((i + 1) < m_size) {
				var = m_data[i + 1];
				m_data[i] = var;
			}
		}
		m_size--;
		return pos;
	}

	iterator erase(iterator first, iterator last) {
		iterator tmp = first;
		do {
			*tmp = *last;
			tmp++;
			last++;
		} while (last != end());
		m_size -= last - first;
		return tmp;
  	}

	void resize( size_type count ) {
		if (count > m_size) {
			this->reserve(count);
			m_size = count;
		}
		for (size_type i = m_size; i > count; i--) {
			_allocator.destroy(m_data + i);
			m_size--;
		}
	}

	void swap( vector& other ) {
		_swap(this->m_capacity, other.m_capacity);
		_swap(this->m_size, other.m_size);
		_swap(this->m_data, other.m_data);
		_swap(this->_allocator, other._allocator);
	}
	
private:
	allocator_type _allocator;
	size_type m_size;
	size_type m_capacity;
	value_type* m_data;

	template<typename J>
	void _swap(J& obj, J& other) {
		J aux = obj;
		obj = other;
		other = aux;
	}

};

template<class T, class Allocator>
bool operator==(const vector<T, Allocator> &lhs,
                const vector<T, Allocator> &rhs) {
  return (
      ft::equal(lhs.begin(),
                lhs.end(),
                rhs.begin()));
}

template<class T, class Allocator>
bool operator!=(const vector<T, Allocator> &lhs,
                const vector<T, Allocator> &rhs) {
  return (
      !(ft::equal(lhs.begin(),
                  lhs.end(),
                  rhs.begin())));
}

template<class T, class Allocator>
bool operator<(const vector<T, Allocator> &lhs,
               const vector<T, Allocator> &rhs) {
  return (
      ft::lexicographical_compare(lhs.begin(),
                                  lhs.end(),
                                  rhs.begin(),
                                  rhs.end()));
}

template<class T, class Allocator>
bool operator<=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs) {
  return !(lhs > rhs);
}

template<class T, class Allocator>
bool operator>(const vector<T, Allocator> &lhs,
               const vector<T, Allocator> &rhs) {
  return (
      ft::lexicographical_compare(rhs.begin(),
                                  rhs.end(),
                                  lhs.begin(),
                                  lhs.end()));
}

template<class T, class Allocator>
bool operator>=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs) {
  return !(lhs < rhs);
}
}
#endif