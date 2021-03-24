#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>

namespace ft {
	template<typename T, class Allocator = std::allocator<T>>
	class list {
	private:
		class node{
		public:
			T			*_data;
			node		*_prev;
			node		*_next;
			node() {}
			node(T data) : _data(data){}
			~node() {}
		};

	public:
		typedef T							value_type;
		typedef Allocator					allocator_type;
		typedef std::size_t					size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef Allocator::reference		reference;
		typedef Allocator::const_reference	const_reference;
		typedef Allocator::pointer			pointer;
		typedef Allocator::const_pointer	const_pointer;
//		typedef iterator;
//		typedef const_iterator;
//		typedef reverse_iterator			std::reverse_iterator<iterator>;
//		typedef const_reverse_iterator		std::reverse_iterator<const_iterator>;

	private:
		size_type		_list_size;
		node			*_head;
		node			*_tail;
		allocator_type	_alloc;
	public:
//		Default constructor. Constructs an empty container with a default-constructed allocator.
		list(){
			_list_size = 0;
			_head = NULL;
			_tail = NULL;
			_alloc = NULL;
		}

//		Constructs an empty container with the given allocator alloc.
		explicit list( const Allocator& alloc ){
			_list_size = 0;
			_head = NULL;
			_tail = NULL;
			_alloc = alloc;
		}

//		Constructs the container with count copies of elements with value value.
		explicit list( size_type count, const T& value = T(), const Allocator& alloc = Allocator()){
			node * tmp;
			node * shadow;
			_list_size = count;
			_alloc = alloc;
			if (_list_size == 0){
				_head = NULL;
				_tail = NULL;
				return;
			}
			shadow = new node();
			_head = new node(value);
			_head->_prev = shadow;
			_head->_next = shadow;
			shadow->_prev = _head;
			shadow->_next = _head;
			_head = _tail;
			for (int i = 1; i < _list_size; i++){
				tmp = new node(value);
				_tail->_next = tmp;
				tmp->_prev = _tail;
				tmp->_next = shadow;
				_tail = tmp;
				shadow->_prev = _tail;
			}
		}

//		Constructs the container with the contents of the range [first, last).
		template< class InputIt >
		list( InputIt first, InputIt last, const Allocator& alloc = Allocator() ){

		}

//		Copy constructor. Constructs the container with the copy of the contents of other, the allocator is obtained as if by calling
		list( const list& other ){

		}

		~list(){

		}


//	public:
//		friend class iterator;
//		class iterator{
//			friend class list<T>;
//		private:
//			node	*_node;
//		public:
//			iterator() : _node(NULL) {}
//			iterator(node *node) : _node(node) {}
//			iterator(const iterator & it) : _node(it._node) {}
//			iterator& operator=(const iterator & it){
//				_node = it._node;
//				return *this;
//			}
//			//Non-member functions
//			bool operator==(const iterator & it) const{
//				return (_node == it._node);
//			}
//			bool operator!=(const iterator & it) const{
//				return (_node != it._node);
////				return (it != *this);
//			}
//			bool operator<(const iterator & it) const{}
//			bool operator<=(const iterator & it) const{}
//			bool operator>(const iterator & it) const{}
//			bool operator>=(const iterator & it) const{}
//			bool operator<=>(const iterator & it) const{}
//
//		}





		};
}


#endif