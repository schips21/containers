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
		typedef typename allocator_type::reference		reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer	const_pointer;
	};
}

#endif