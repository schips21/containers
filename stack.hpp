#ifndef STACK_HPP
# define STACK_HPP

#include "list.hpp"

namespace ft{
	template<class T,class Container = ft::list<T> >
	class stack{
	public:
		typedef Container					container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

	protected:
		Container C;

	public:
		explicit stack( const Container& cont = Container() ) : C(cont){}

		stack( const stack& other ) : C(other.C){}

		~stack(){}

		stack& operator=( const stack& other ){
			C = other.C;
			return (*this);
		}

		reference top(){
			return (C.back());
		}

		const_reference top() const{
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
			C.pop_back();
		}

		template< class T_, class Container_ >
		friend bool operator==( const stack<T_,Container_>& lhs, const ft::stack<T_,Container_>& rhs );

		template< class T_, class Container_ >
		friend bool operator!=( const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs );

		template< class T_, class Container_ >
		friend bool operator<( const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs );

		template< class T_, class Container_ >
		friend bool operator<=( const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs );

		template< class T_, class Container_ >
		friend bool operator>( const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs );

		template< class T_, class Container_ >
		friend bool operator>=( const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs );
	};

	template< class T, class Container >
	bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
		return (lhs.C == rhs.C);
	}

	template< class T, class Container >
	bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
		return (lhs.C != rhs.C);
	}

	template< class T, class Container >
	bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
		return (lhs.C < rhs.C);
	}

	template< class T, class Container >
	bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
		return (lhs.C <= rhs.C);
	}

	template< class T, class Container >
	bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
		return (lhs.C > rhs.C);
	}

	template< class T, class Container >
	bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
		return (lhs.C >= rhs.C);
	}
}

#endif