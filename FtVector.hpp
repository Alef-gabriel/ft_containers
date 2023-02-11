#ifndef FtVECTOR_HPP
#define FtVECTOR_HPP
#include <iostream>
#include <initializer_list>
#include <memory>
#include <cstddef>
#include <algorithm>

namespace ft {
template<class T, class Allocator = std::allocator<T> >
class vector
{
public:
	typedef Allocator 						allocator_type;
	typedef T	value_type;
	typedef typename std::vector<value_type>::iterator iterator;
	typedef typename std::reverse_iterator<iterator>		reverse_iterator;

	vector() : m_size(0), m_capacity(0), m_data(NULL) {}

	vector(std::initializer_list<value_type> data) {
		m_size = data.size();
		m_capacity = data.size();
		m_data =  _allocator.allocate(data.size());
		for (size_t i = 0; i < data.size(); i++) {
			m_data[i] = *(data.begin() + i);
		}
	}

	explicit vector (const allocator_type &alloc): _allocator(alloc), m_size(0), m_capacity(0), m_data(NULL) {}

	vector (vector const & obj){
		std::cout << "Copy" << '\n';
		*this = obj;
	}

	explicit vector (size_t count,
					const value_type &value = value_type(),
					const allocator_type &alloc = allocator_type()) {
		m_size =  count;
		m_capacity = count;
		_allocator = alloc;
		m_data =  _allocator.allocate(count);
		for (size_t i = 0; i < count; i++) {
			_allocator.construct(m_data, value);
		}
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

	value_type & at(int i){
		return m_data[i];
	}
	
	value_type * data(){
		return m_data;
	}

	value_type & front(void){
		return m_data[0];
	}

	value_type & back(void){
		return m_data[m_size - 1];
	}

	value_type & rbegin(void){
		return m_data[m_size - 1];
	}

	value_type & rend(void){
		return m_data[0];
	}

	bool empty(void) const {
		if (m_size == 0)
			return true;
		return false;
	}

	size_t size() const{
		return m_size;
	}

	size_t max_size() const{
		return _allocator.max_size();
	}

	void push_back(value_type data){
		size_t	newCapacity;

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

	size_t size(void){
		return m_size;
	}

	bool empty(void){
		if (m_size > 0)
			return false;
		return true;
	}

	size_t capacity() const {
		return m_capacity;
	}

	void reserve( size_t new_cap ) {
		value_type* newBlock = _allocator.allocate(new_cap);
		for (size_t i = 0; i < m_size; i++)
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

	//TODO UPDATE TO CONST_ITERATOR
	iterator insert( iterator pos, value_type&& value ) {
		size_t index = std::distance( this->begin(), pos);
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
			for (size_t i = index; i < (m_size + 1); i++) {
				var = m_data[i];
				m_data[i] = aux;
				aux = var;
			}
			m_size++;
		}
		return pos;
	}

	iterator erase( iterator pos ) {
		size_t index = std::distance( this->begin(), pos);
		if (index > m_size) {
			return pos;
		}
		value_type var;
		_allocator.destroy(m_data + index);
		for (size_t i = index; i < m_size; i++) {
			if ((i + 1) < m_size) {
				var = m_data[i + 1];
				m_data[i] = var;
				std::cout << i << '\n';
			}
		}
		m_size--;
		return pos;
	}

	void resize( size_t count ) {
		if (count > m_size) {
			this->reserve(count);
			m_size = count;
		}
		for (size_t i = m_size; i > count; i--) {
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
	
	template< class T, class Allocator >
	friend bool operator==(const vector<T, Allocator>& lhs,
					const vector<T, Allocator>& rhs ) {
		return (std::equal(lhs.begin(),lhs.end(), rhs.begin()));
	}

	template< class T, class Alloc >
	friend bool operator!=( const std::vector<T, Alloc>& lhs,
					const std::vector<T, Alloc>& rhs ) {
		return (!(std::equal(lhs.begin(),lhs.end(), rhs.begin())));
	}

private:
	allocator_type _allocator;
	size_t m_size;
	size_t m_capacity;
	value_type* m_data;

	template<typename J>
	void _swap(J& obj, J& other) {
		J aux = obj;
		obj = other;
		other = aux;
	}

};
}
#endif