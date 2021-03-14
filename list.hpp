#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>

namespace ft {
	template<typename T>
	class list {
	public:
		list();
		list(const list& other);
		list & operator=( const list& other );
		~list();

	private:
		friend class node;
		class node{
		public:
			friend class list<T>;
			friend class iterator;

			T			*_data;
			node		*_prev;
			node		*_next;

			node() {}
			node(T data) : _data(data){}
			~node() {}
		};

	public:
		friend class iterator;
		class iterator{
			friend class list<T>;
		private:
			node	*_node;
		public:
			iterator() : _node(NULL) {}
			iterator(node *node) : _node(node) {}
			iterator(const iterator & it) : _node(it._node) {}
			iterator& operator=(const iterator & it){
				_node = it._node;
				return *this;
			}
			//Non-member functions
			bool operator==(const iterator & it) const{
				return (_node == it._node);
			}
			bool operator!=(const iterator & it) const{
				return (_node != it._node);
//				return (it != *this);
			}
			bool operator<(const iterator & it) const{}
			bool operator<=(const iterator & it) const{}
			bool operator>(const iterator & it) const{}
			bool operator>=(const iterator & it) const{}
			bool operator<=>(const iterator & it) const{}

		}





		};
}


#endif