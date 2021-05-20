#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace ft{
	template<class T, class Allocator = std::allocator<T> >
	class vector{
	public:
		typedef T							value_type;
		typedef Allocator					allocator_type;
		typedef std::size_t					size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef typename allocator_type::reference		reference; //value_type&
		typedef typename allocator_type::const_reference	const_reference; //const value_type&
		typedef typename allocator_type::pointer			pointer; // value_type*
		typedef typename allocator_type::const_pointer	const_pointer; //const value_type*

	private:
		allocator_type	_alloc;
		size_type		_size;
		size_type		_capacity;
		pointer			_data;

	public:
		vector(){
			_size = 0;
			_capacity = 0;
			_data = NULL;
		}

		explicit vector (const allocator_type& alloc = allocator_type()){
			_alloc = alloc;
			_size = 0;
			_capacity = 0;
			_data = NULL;
		}

		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type()){
			_alloc = alloc;
			_size = n;
			_capacity = n;
			_data = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_data + i, val);
		}

//		template <class InputIterator>
//		vector (InputIterator first, InputIterator last,
//				const allocator_type& alloc = allocator_type()){
//
//		}

//		vector (const vector& x){
//
//		}

		~vector(){
			this->delete_vect();
		}

//		vector& operator= (const vector& x){
//			if (this == x){
//				return *this;
//			}
//			this->delete_vect();
//
//		}

//		Capacity

		size_type size() const{
			return _size;
		}

		size_type max_size() const{
			return (std::numeric_limits<size_type>::max() / sizeof(T));
		}

//		void resize (size_type n, value_type val = value_type()){
//			if (n < _size){
//				while (_size > n)
//					this->pop_back(val);
//			}
//			else if (n > _size){
//				if (n > _capacity){
//					this->resize(_capacity * 2 > n ? _capacity * 2 : n);
//				}
//				while (_size < n)
//					this->push_back(val);
//			}
//		}

		size_type capacity() const{
			return _capacity;
		}

		bool empty() const{
			if (_size == 0){
				return true;
			}
			return false;
		}

		void capacity_realloc(size_type n){
			pointer tmp = this->_alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(tmp + i, _data[i]);
			size_type tmp_size = _size;
			this->delete_vect();
			_size = tmp_size;
			_capacity = n;
			_data = tmp;
		}

		void reserve (size_type n){
			if (n <= this->_capacity)
				return;
			if (n > max_size())
				throw std::length_error("reserve: too big size to reallocate");
			capacity_realloc(n);
		}

//		Element access:

		reference operator[] (size_type n){
			return _data[n];
		}

		const_reference operator[] (size_type n) const{
			return _data[n];
		}

//		Modifiers

		void push_back (const value_type& val){
			if (_size + 1 > _capacity)
				this->capacity_realloc(_capacity == 0 ? 1 : _capacity * 2);
			_alloc.construct(_data + _size, val);
			_size++;
		}

		void pop_back(){
			if (_size > 0){
				_alloc.destroy(_data + (_size - 1));
				_size--;
			}
		}

//		Utils

		void delete_vect(){
			if (this->_size != 0){
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
				_alloc.deallocate(_data, _capacity);
				_capacity = 0;
				_size = 0;
			}
		}



	};
}

#endif