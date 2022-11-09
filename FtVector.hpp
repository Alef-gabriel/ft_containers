#ifndef FtVECTOR_HPP
#define FtVECTOR_HPP
#include <iostream>

template<typename T>
class FtVector
{
	private:
		T* m_data = nullptr;
		size_t m_size;
		size_t m_capacity;

		void ReAlloc(size_t newCapacity)
		{
			T* newBlock = new T[newCapacity];
			if (newCapacity < m_size)
				m_size = newCapacity;
			for (size_t i = 0; i < m_size; i++)
				newBlock[i] = m_data[i];
			delete[] m_data;
			m_data = newBlock;
			m_capacity = newCapacity;
		}

	public:
		FtVector(void) : m_size(0), m_capacity(0) {}
		~FtVector(void){
			delete[] m_data;
		}

		T & operator[](int i){
			return m_data[i];
		}

		T & front(void){
			return m_data[0];
		}

		T & back(void){
			return m_data[m_size - 1];
		}

		void push_back(T data){
			size_t	newCapacity;

			newCapacity = m_capacity + 1;
			if (m_capacity <= m_size)
				ReAlloc(newCapacity);
			m_size++;
			m_data[m_size - 1] = data;
		}

		size_t capacity(void){
			return m_capacity;
		}

		size_t size(void){
			return m_size;
		}

		bool empty(void){
			if (m_size > 0)
				return false
			return true;
		}
};
#endif