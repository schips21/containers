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
			for (size_type i = 0; i < _size; ++i)
				_alloc.construct(_data + i, val);
		}
	};
}

#endif