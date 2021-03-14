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

			T			*data;
			node		*prev;
			node		*next;


		};


}


#endif