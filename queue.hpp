#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "list.hpp"

namespace ft{
	template<class T,class Container = ft::list<T> >
	class queue{
	public:
		typedef Container					container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

	protected:
		Container C;

	public:
		explicit queue( const Container& cont = Container() ) : C(cont){}

		queue( const queue& other ) : C(other.C){}

		~queue(){}

		queue& operator=( const queue& other ){
			C = other.C;
			return (*this);
		}

		reference front(){
			return (C.front());
		}

		const_reference front() const{
			return (C.front());
		}

		reference back(){
			return (C.back());
		}

		const_reference back() const{
			return (C.back());
		}

		bool empty() const{
			return (C.empty());
		}

		size_type size() const{
			return (C.size());
		}

		void push( const value_type& value ){
			C.push_back(value);
		}

		void pop(){
			C.pop_front();
		}

		template< class T_, class Container_ >
		friend bool operator==( const queue<T_,Container_>& lhs, const ft::queue<T_,Container_>& rhs );

		template< class T_, class Container_ >
		friend bool operator!=( const queue<T_,Container_>& lhs, const queue<T_,Container_>& rhs );

		template< class T_, class Container_ >
		friend bool operator<( const queue<T_,Container_>& lhs, const queue<T_,Container_>& rhs );

		template< class T_, class Container_ >
		friend bool operator<=( const queue<T_,Container_>& lhs, const queue<T_,Container_>& rhs );

		template< class T_, class Container_ >
		friend bool operator>( const queue<T_,Container_>& lhs, const queue<T_,Container_>& rhs );

		template< class T_, class Container_ >
		friend bool operator>=( const queue<T_,Container_>& lhs, const queue<T_,Container_>& rhs );
	};

	template< class T, class Container >
	bool operator==( const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs ){
		return (lhs.C == rhs.C);
	}

	template< class T, class Container >
	bool operator!=( const queue<T,Container>& lhs, const queue<T,Container>& rhs ){
		return (lhs.C != rhs.C);
	}

	template< class T, class Container >
	bool operator<( const queue<T,Container>& lhs, const queue<T,Container>& rhs ){
		return (lhs.C < rhs.C);
	}

	template< class T, class Container >
	bool operator<=( const queue<T,Container>& lhs, const queue<T,Container>& rhs ){
		return (lhs.C <= rhs.C);
	}

	template< class T, class Container >
	bool operator>( const queue<T,Container>& lhs, const queue<T,Container>& rhs ){
		return (lhs.C > rhs.C);
	}

	template< class T, class Container >
	bool operator>=( const queue<T,Container>& lhs, const queue<T,Container>& rhs ){
		return (lhs.C >= rhs.C);
	}
}

#endif