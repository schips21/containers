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

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(), typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0){
			_alloc = alloc;
			_size = 0;
			_capacity = 0;
			_data = NULL;
			while (first != last){
				this->push_back(*first);
				first++;
			}
		}

		vector (const vector& x){
			_size = 0;
			_capacity = 0;
			_data = NULL;
			*this = x;
		}

		~vector(){
			this->delete_vect();
		}

		vector& operator= (const vector& x){
			if (*this == x){
				return *this;
			}
			this->delete_vect();
//			this->_capacity = x._capacity;
			this->_alloc = x._alloc;
			iterator it = x.begin();
			iterator ite = x.end();
			while (it != ite){
				this->push_back(*it++);
			}
			return *this;
		}

//		Iterators

	private:
		class it_general{
		protected:
			pointer _it;
		public:
			it_general(){
				_it = NULL;
			}
			explicit it_general(pointer it){
				_it = it;
			}
			virtual ~it_general(){}
			//конструктор копирования и оператор = в классе итератор
			bool operator==(const it_general& rhs) const{
				return (this->_it == rhs._it);
			}
			bool operator!=(const it_general& rhs) const{
				return (this->_it != rhs._it);
			}

			T &operator*() const{
				return *(this->_it);
			}
			T *operator->() const{
				return (this->_it);
			}
			bool operator<(const it_general& rhs) const{
				return (this->_it < rhs._it);
			}
			bool operator>(const it_general& rhs) const{
				return (this->_it > rhs._it);
			}
			bool operator<=(const it_general& rhs) const{
				return (*this < rhs || *this == rhs);
			}
			bool operator>=(const it_general& rhs) const{
				return (*this > rhs || *this == rhs);
			}
			reference operator[] (size_type n){
				return (this->_it[n]);
			}
		};

	public:
		typedef class iterator : public it_general{
		public:
			iterator() : it_general(){}
			explicit iterator(pointer it) : it_general(it){}
			iterator& operator=(const iterator& rhs) {
				if (*this == rhs)
					return *this;
				this->_it = rhs._it;
				return *this;
			}
			iterator(const iterator& rhs){
				this->_it = rhs._it;
			}
			virtual ~iterator(){}
			iterator& operator++() {
				this->_it++;
				return *this;
			}
			iterator& operator--() {
				this->_it--;
				return *this;
			}
			iterator operator++(int) {
				iterator prev_it(*this);
				this->_it++;
				return prev_it;
			}
			iterator operator--(int) {
				iterator prev_it(*this);
				this->_it--;
				return prev_it;
			}
			iterator &operator+=(int n){
				this->_it += n;
				return *this;
			}
			iterator operator+(int n){
				iterator tmp(*this);
				return tmp += n;
			}
			iterator &operator-=(int n){
				this->_it -= n;
				return *this;
			}
			iterator operator-(int n){
				iterator tmp(*this);
				return tmp -= n;
			}
		}				iterator;

		typedef class const_iterator : public iterator {
		public:
			const_iterator() : iterator(){}
			explicit const_iterator(pointer it) : iterator(it){}
			explicit const_iterator(const iterator& rhs) : iterator(rhs){}
			virtual ~const_iterator(){}
			const T &operator*() const{
				return *(this->_it);
//				return (this->_it->_data);
			}
		}				const_iterator;

		typedef class reverse_iterator : public it_general{
		public:
			reverse_iterator() : it_general(){}
			explicit reverse_iterator(pointer it) : it_general(it){}
			reverse_iterator& operator=(const reverse_iterator& rhs) {
				if (*this == rhs)
					return *this;
				this->_it = rhs._it;
				return *this;
			}
			reverse_iterator(const reverse_iterator& rhs){
				this->_it = rhs._it;
			}
			virtual ~reverse_iterator(){}
			reverse_iterator& operator++() {
				this->_it--;
				return *this;
			}
			reverse_iterator& operator--() {
				this->_it++;
				return *this;
			}
			reverse_iterator operator++(int) {
				reverse_iterator prev_it(*this);
				this->_it--;
				return prev_it;
			}
			reverse_iterator operator--(int) {
				reverse_iterator prev_it(*this);
				this->_it++;
				return prev_it;
			}
			reverse_iterator &operator+=(int n){
				this->_it -= n;
				return *this;
			}
			reverse_iterator operator+(int n){
				reverse_iterator tmp(*this);
				return tmp -= n;
			}
			reverse_iterator &operator-=(int n){
				this->_it += n;
				return *this;
			}
			reverse_iterator operator-(int n){
				reverse_iterator tmp(*this);
				return tmp += n;
			}
		}				reverse_iterator;

		typedef class const_reverse_iterator : public reverse_iterator {
		public:
			const_reverse_iterator() : reverse_iterator(){}
			explicit const_reverse_iterator(pointer it) : reverse_iterator(it){}
			explicit const_reverse_iterator(const reverse_iterator& rhs) : reverse_iterator(rhs){}
			virtual ~const_reverse_iterator(){}
			const T &operator*() const{
				return *(this->_it);
//				return (this->_it->_data);
			}
		}				const_reverse_iterator;

		iterator begin(){
			return (iterator(this->_data));
		}
		const_iterator begin() const{
			return (const_iterator(this->_data));
		}
		iterator end(){
			return (iterator(this->_data + _size));
		}
		const_iterator end() const{
			return (const_iterator(this->_data + _size));
		}
		reverse_iterator rbegin(){
			return (reverse_iterator(this->_data + (_size - 1)));
		}
		const_reverse_iterator rbegin() const{
			return (const_reverse_iterator(this->_data + (_size - 1)));
		}
		reverse_iterator rend(){
			return (reverse_iterator(this->_data - 1));
		}
		const_reverse_iterator rend() const{
			return (const_reverse_iterator(this->_data - 1));
		}


//		Capacity

		size_type size() const{
			return _size;
		}

		size_type max_size() const{
			return (std::numeric_limits<size_type>::max() / sizeof(T));
		}

		void resize (size_type n, value_type val = value_type()){
			if (n < _size){
				while (_size > n)
					this->pop_back();
			}
			else if (n > _size){
				if (n > _capacity){
					this->capacity_realloc(_capacity * 2 > n ? _capacity * 2 : n);
				}
				while (_size < n)
					this->push_back(val);
			}
		}

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

		reference at (size_type n){
			if (n >= _size)
				throw std::out_of_range("invalid index");
			return _data[n];
		}

		const_reference at (size_type n) const{
			if (n >= _size)
				throw std::out_of_range("invalid index");
			return _data[n];
		}

		reference front(){
			return _data[0];
		}

		const_reference front() const{
			return _data[0];
		}

		reference back(){
			return _data[_size - 1];
		}

		const_reference back() const{
			return _data[_size - 1];
		}

//		Modifiers

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last){
			int n = 0;
			InputIterator tmp = first;
			while (tmp++ != last)
				n++;
			this->clear();
			if (n > _capacity){
				_alloc.deallocate(_data, _capacity);
				_data = _alloc.allocate(n);
				_capacity = n;
			}
			while (first != last)
				this->push_back(*first++);
		}

		void assign (size_type n, const value_type& val){
			this->clear();
			if (n > _capacity){
				_alloc.deallocate(_data, _capacity);
				_data = _alloc.allocate(n);
				_capacity = n;
			}
			for (int i = 0; i < n; i++)
				this->push_back(val);
		}

		void push_back (const value_type& val){
			if (_size + 1 > _capacity)
//				this->capacity_realloc(_capacity + 1);
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

		iterator insert (iterator position, const value_type& val){
			if (position == this->end()) {
				this->push_back(val);
				return iterator(_data + (_size - 1));
			}
			int len = 0;
			iterator it_start = this->begin();
			while (it_start++ != position) {
				len++;
			}
			if (_size + 1 > _capacity)
				this->capacity_realloc(_capacity == 0 ? 1 : _capacity * 2);
			T tmp;
			T tmp2 = val;
			int i = len;
			for (; i < this->size(); i++) {
				tmp = _data[i];
				_alloc.destroy(_data + i);
				_alloc.construct(_data + i, tmp2);
				tmp2 = tmp;
			}
			_alloc.construct(_data + i, tmp2);
			_size++;
			return iterator(_data + len);
		}

		void swap (vector& x){
//			if (x == *this)
//				return;
			allocator_type tmp_alloc;
			size_type tmp_size;
			size_type tmp_capacity;
			pointer tmp_data;

			tmp_alloc = this->_alloc;
			this->_alloc = x._alloc;
			x._alloc = tmp_alloc;

			tmp_size = this->_size;
			this->_size = x._size;
			x._size = tmp_size;

			tmp_capacity = this->_capacity;
			this->_capacity = x._capacity;
			x._capacity = tmp_capacity;

			tmp_data = this->_data;
			this->_data = x._data;
			x._data = tmp_data;
		}

		void clear(){
			while (_size > 0)
				this->pop_back();
		}

		allocator_type get_allocator() const{
			return std::allocator<T>(_alloc);
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

//	template<class T, class Allocator>
//	vector<T, Allocator>::iterator::~iterator() {
//
//	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return false;
		typename ft::vector<T>::const_iterator it_lhs = lhs.begin();
		typename ft::vector<T>::const_iterator it_rhs = rhs.begin();
		typename ft::vector<T>::const_iterator ite_lhs = lhs.end();
		while (it_lhs != ite_lhs){
			if (*it_lhs != *it_rhs)
				return false;
			it_lhs++;
			it_rhs++;
		}
		return true;
	}
}

#endif