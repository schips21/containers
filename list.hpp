#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>

namespace ft {
	template<typename T, class Allocator = std::allocator<T>>
	class list {
	private:
		class node{
		public:
			T			_data;
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
		typedef typename allocator_type::reference		reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer	const_pointer;
//		typedef iterator;
//		typedef const_iterator;
//		typedef reverse_iterator			std::reverse_iterator<iterator>;
//		typedef const_reverse_iterator		std::reverse_iterator<const_iterator>;

	private:
		size_type		_list_size;
		node			*_head;
		node			*_tail;
		node			*_shadow;
		Allocator		_alloc;
	public:
//		Default constructor. Constructs an empty container with a default-constructed allocator.
		list(){
			_list_size = 0;
			_head = _tail = _shadow = new node;
		}

//		Constructs an empty container with the given allocator alloc.
		explicit list( const Allocator& alloc ){
			_list_size = 0;
			_head = _tail = _shadow = new node;
			_alloc = alloc;
		}

//		Constructs the container with count copies of elements with value value.
		explicit list( size_type count, const T& value = T(), const Allocator& alloc = Allocator()){
			node * tmp;
			_list_size = count;
			_alloc = alloc;
			if (_list_size == 0){
				_head = _tail = _shadow = new node;
				return;
			}
			_shadow = new node();
			_head = new node(value);
			_head->_prev = _shadow;
			_head->_next = _shadow;
			_shadow->_next = _head;
			for (int i = 1; i < _list_size; i++){
//				убрать +i
				tmp = new node(value);
				_head->_next = tmp;
				tmp->_prev = _head;
				_head = tmp;
				_head->_next = _shadow;

			}
			_shadow->_prev = _head;
			_head = _shadow->_next;
			_tail = _shadow->_prev;
			_tail->_prev = _shadow->_prev->_prev;
		}

//		Constructs the container with the contents of the range [first, last).
//		template< class InputIt >
//		list( InputIt first, InputIt last, const Allocator& alloc = Allocator() ){
//
//		}

//		Copy constructor. Constructs the container with the copy of the contents of other, the allocator is obtained as if by calling
//		list( const list& other ){
//
//		}

		~list(){
			this->clear();
		}

//		list& operator=( const list& other ){
//
//		}

		void assign( size_type count, const T& value ){
			this->clear();
			node * tmp;
			if (count == 0){
				_head = _tail = _shadow = new node;
				return;
			}
			_head = _tail = _shadow = new node();
			for (int i = 0; i < count; i++){
				this->push_back(value);
			}
		}

//		template< class InputIt >
//		void assign( InputIt first, InputIt last ){
//
//		}

//		ELEMENT ACCESS
		value_type front(){
			return this->_head->_data;
		}

		value_type back(){
			return this->_tail->_data;
		}

//		ITERATORS
		class it_general{
		protected:
			node *_it;
		public:
			it_general(){
				_it = NULL;
			}
			explicit it_general(node *it){
				_it = it;
			}
//			конструктор копирования и оператор = в классе итератор
			~it_general(){}
			bool operator==(const it_general& rhs) const{
				return (this->_it == rhs._it);
			}
			bool operator!=(const it_general& rhs) const{
				return (this->_it != rhs._it);
			}
			T &operator*() const{
				return (this->_it->_data);
			}
			T *operator->() const{
				return (&(this->_it->_data));
			}
			friend class list<T>;
		};

		typedef class iterator : public it_general{
		public:
			iterator() : it_general(){}
			explicit iterator(node *it) : it_general(it){}
			iterator& operator=(const iterator& rhs) {
				if (*this == rhs)
					return *this;
				this->_it = rhs._it;
				return *this;
			}
			iterator(const iterator& rhs){
				this->_it = rhs._it;
			}
			iterator& operator++() {
				if (this->_it && this->_it->_next)
					this->_it = this->_it->_next;
				return *this;
			}
			iterator& operator--() {
				if (this->_it && this->_it->_prev)
					this->_it = this->_it->_prev;
				return *this;
			}
			iterator operator++(int) {
				iterator prev_it(*this);
				if (this->_it && this->_it->_next)
					this->_it = this->_it->_next;
				return prev_it;
			}
			iterator operator--(int) {
				iterator prev_it(*this);
				if (this->_it && this->_it->_prev)
					this->_it = this->_it->_prev;
				return prev_it;
			}
		}				iterator;

		typedef class const_iterator : public iterator {
		public:
			const_iterator() : iterator(){}
			explicit const_iterator(node *it) : iterator(it){}
			const_iterator(const iterator& rhs) : iterator(rhs){}
			const T &operator*() const{
				return (this->_it->_data);
			}
		}				const_iterator;

		iterator begin(){
			return iterator(this->_head);
		}

		const_iterator begin() const{
			return iterator(this->_head);
		}

		iterator end(){
			return iterator(this->_shadow);
		}

		const_iterator end() const{
			return iterator(this->_shadow);
		}


//		CAPACITY
		bool empty() const{
			if (_tail == _head && _head == _shadow)
				return true;
			return false;
		}

		size_type size() const{
			return this->_list_size;
		}

		size_type max_size() const{
			return (std::numeric_limits<size_type>::max() / sizeof(node));
		}


//		MODIFIERS
		void clear(){
			if (_head != NULL && _head != _shadow){
				node * tmp;
				tmp = _head;
				while (tmp != _shadow){
					tmp = tmp->_next;
					delete tmp->_prev;
				}
			_head = _tail = _shadow = NULL;
			}
			_list_size = 0;
		}

//		Insert

//		Erase

		void push_back( const T& value ){
			_list_size++;
			if (_head == _tail && _head == _shadow){
				_head = _tail = new node(value);
				_head->_prev = _shadow;
				_head->_next = _shadow;
				_shadow->_next = _head;
				_shadow->_prev = _tail;
			}
			else{
				node * tmp;
				tmp = new node(value);
//				_tail->_prev->_next = tmp;
				_tail->_next = tmp;
				tmp->_prev = _tail;
				_tail = tmp;
				tmp->_next = _shadow;
				_shadow->_prev = tmp;
			}
		}

		void pop_back(){
			if (_list_size != 0){
				_tail->_prev->_next = _shadow;
				_shadow->_prev = _tail->_prev;
				_tail = _tail->_prev;
				_list_size--;
				if (_list_size == 0){
					_head = _tail;
				}
			}
		}

		void push_front( const T& value ){
			_list_size++;
			if (_head == _tail && _head == _shadow){
				_head = _tail = new node(value);
				_head->_prev = _shadow;
				_head->_next = _shadow;
				_shadow->_next = _head;
				_shadow->_prev = _tail;
			}
			else{
				node * tmp;
				tmp = new node(value);
				_head->_prev = tmp;
				tmp->_next = _head;
				_shadow->_next = tmp;
				tmp->_prev = _shadow;
				_head = tmp;
			}
		}

		void pop_front(){
			if (_list_size != 0){
				_head->_next->_prev = _shadow;
				_shadow->_next = _head->_next;
				_head = _head->_next;
				_list_size--;
				if (_list_size == 0){
					_tail = _head;
				}
			}
		}

		void resize( size_type count, T value = T() ){
			if (_list_size > count){
				while (_list_size != count){
					this->pop_back();
				}
			}
			else if (_list_size < count){
				while (_list_size < count){
					this->push_back(value);
				}
			}
		}

		void swap( list& other ){
			node * tmp;
			tmp = this->_head;
			this->_head = other._head;
			other._head = tmp;

			tmp = this->_tail;
			this->_tail = other._tail;
			other._tail = tmp;

			tmp = this->_shadow;
			this->_shadow = other._shadow;
			other._shadow = tmp;

			int tmp_size = this->_list_size;
			this->_list_size = other._list_size;
			other._list_size = tmp_size;
		}

	};
}


#endif