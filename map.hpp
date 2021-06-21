#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>,
	class Alloc = std::allocator<std::pair<const Key,T>>>
	class map{
	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef std::pair<const key_type,mapped_type>		value_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef std::ptrdiff_t				difference_type;
		typedef std::size_t					size_type;

		typedef class value_compare {
		private:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
		protected:
			Compare comp;
		protected:
			value_compare() {
				comp = std::less<T>();
			}
			value_compare(Compare new_comp){
				comp = new_comp;
			}
			bool operator()( const value_type& lhs, const value_type& rhs ) const{
				return comp(lhs.first, rhs.first);
			}
		}				value_compare;
	private:
		class node{
		public:
			value_type value;
			node *parent;
			node *left_child;
			node *right_child;
			node() {}
			node(const value_type& val) : value(val){
			}
			node(const node & other) : value(other.value){

			}
			~node() {}
		};
	private:
		node		*_root;
		node		*_shadow;
		size_type	_size;
		Alloc		_alloc;
		Compare		_compare;

		void make_shadow(){
			_shadow = new node();
			_shadow->parent = NULL;
			_shadow->left_child = NULL;
			_shadow->right_child = NULL;
		}

	public:
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()){
			_size = 0;
			_compare = comp;
			_alloc = alloc;
			make_shadow();
			_root = _shadow;
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()){
			_size = 0;
			_compare = comp;
			_alloc = alloc;
			make_shadow();
			_root = _shadow;
			while (first != last) {
				this->insert_elem(*first);
				first++;
			}
		}

		map (const map& x){
			this->_size = 0;
			this->_alloc = x._alloc;
			this->_compare = x._compare;
			make_shadow();
			_root = _shadow;
			iterator it = x.begin();
			iterator ite = x.end();
			while (it != ite) {
				this->insert_elem(*it);
				it++;
			}
		}
		~map(){
			this->clear();
		}

		map& operator= (const map& x){
			if (*this == x)
				return *this;
			if (this->_size != 0)
				this->clear();
			this->_compare = x._compare;
			this->_alloc = x._alloc;

			this->_shadow = this->_root = new node(*x._shadow);
			this->insert(x.begin(), x.end());
			return *this;
		}

//		Capacity
		bool empty() const{
			if (_size == 0)
				return true;
			return false;
		}
		size_type size() const{
			return _size;
		}
		size_type max_size() const{
			return (std::numeric_limits<size_type>::max() / sizeof(node));
		}

//		Element access
		mapped_type& operator[] (const key_type& k){
			node *tmp = _root;
			if (_root == _shadow) {
				return create_root(std::pair<T, T>(k, NULL));
			}
			while(tmp != _shadow){
				if (!_compare(k, tmp->value.first) && !_compare(tmp->value.first, k))
					return tmp->value.second;
				else if (_compare(k, tmp->value.first)) {
					if (tmp->left_child == _shadow)
						break;
					tmp = tmp->left_child;
				}
				else{
					if (tmp->right_child == _shadow)
						break;
					tmp = tmp->right_child;
				}
			}
			if (_compare(k, tmp->value.first)){
				tmp->left_child = new node(std::pair<T, T>(k, NULL));
				tmp->left_child->parent = tmp;
				tmp = tmp->left_child;
				tmp->left_child = tmp->right_child = _shadow;
			}
			else{
				tmp->right_child = new node(std::pair<T, T>(k, NULL));
				tmp->right_child->parent = tmp;
				tmp = tmp->right_child;
				tmp->left_child = tmp->right_child = _shadow;
			}
			_size++;
			return tmp->value.second;
		}

		mapped_type& create_root(const value_type& val) {
			_root = new node(val);
			_root->parent = _root->left_child = _root->right_child = _shadow;
			_shadow->parent = _shadow->left_child = _shadow->right_child = _root;
			_size++;
			return _root->value.second;
		}

		node *find_max_key() const{
			node *tmp = _root;
			while (tmp->right_child != _shadow)
				tmp = tmp->right_child;
			return tmp;
		}
		node *find_min_key() const{
			node *tmp = _root;
			while (tmp->left_child != _shadow)
				tmp = tmp->left_child;
			return tmp;
		}

//	ITERATORS
	private:
		class it_general{
		protected:
			node *_it;
			node *_shad;

			node *max_node(node *start) {
				while (start->right_child != _shad)
					start = start->right_child;
				return start;
			}
			node *min_node(node *start) {
				while (start->left_child != _shad)
					start = start->left_child;
				return start;
			}
		public:
			it_general(){
				_it = NULL;
				_shad = NULL;
			}
			it_general(node *it, node *shadow){
				_it = it;
				_shad = shadow;
			}
//			конструктор копирования и оператор = в классе итератор
			~it_general(){}
			bool operator==(const it_general& rhs) const{
				return (this->_it == rhs._it);
			}
			bool operator!=(const it_general& rhs) const{
				return (this->_it != rhs._it);
			}

			value_type &operator*(){
				return (this->_it->value);
			}
			value_type *operator->() const{
				return (&(this->_it->value));
			}
			friend class map<Key, T>;
			friend class node;
		};
	public:
		typedef class iterator : public it_general {
		public:
			iterator() : it_general(){}
			iterator(node *it, node *shadow) : it_general(it, shadow){}
			iterator& operator=(const iterator& rhs) {
				if (*this == rhs)
					return *this;
				this->_it = rhs._it;
				this->_shad = rhs._shad;
				return *this;
			}
			iterator(const iterator& rhs){
				this->_it = rhs._it;
				this->_shad = rhs._shad;
			}
			virtual ~iterator(){}
			iterator& operator++() {
				if (this->_it->right_child != this->_shad)
					this->_it = this->min_node(this->_it->right_child);
				else {
					while (this->_it->parent != this->_shad && this->_it->parent->left_child != this->_it)
						this->_it = this->_it->parent;
					this->_it = this->_it->parent;
				}
				return *this;
			}
			iterator operator++(int) {
				iterator prev_it(*this);
				++(*this);
				return prev_it;
			}
			iterator& operator--() {
				if (this->_it == this->_shad || this->_it->left_child != this->_shad)
					this->_it = this->max_node(this->_it->left_child);
				else {
					while (this->_it->parent != this->_shad && this->_it->parent->right_child != this->_it)
						this->_it = this->_it->parent;
					this->_it = this->_it->parent;
				}
				return *this;
			}
			iterator operator--(int) {
				iterator prev_it(*this);
				--(*this);
				return prev_it;
			}
		}				iterator;

		typedef class const_iterator : public iterator {
		public:
			const_iterator() : iterator(){}
			const_iterator(node *it, node *shadow) : iterator(it, shadow){}
			const_iterator(const iterator& rhs) : iterator(rhs){}
			virtual ~const_iterator(){}
			const value_type &operator*() const{
				return (this->_it->value);
			}
		}				const_iterator;

		typedef class reverse_iterator : public it_general {
		public:
			reverse_iterator() : it_general(){}
			reverse_iterator(node *it, node *shadow) : it_general(it, shadow){}
			reverse_iterator& operator=(const reverse_iterator& rhs) {
				if (*this == rhs)
					return *this;
				this->_it = rhs._it;
				this->_shad = rhs._shad;
				return *this;
			}
			reverse_iterator(const reverse_iterator& rhs){
				this->_it = rhs._it;
				this->_shad = rhs._shad;
			}
			virtual ~reverse_iterator(){}
			reverse_iterator& operator++() {
				if (this->_it->left_child != this->_shad)
					this->_it = this->max_node(this->_it->left_child);
				else {
					while (this->_it->parent != this->_shad && this->_it->parent->right_child != this->_it)
						this->_it = this->_it->parent;
					this->_it = this->_it->parent;
				}
				return *this;
			}
			reverse_iterator& operator++(int) {
				reverse_iterator prev_it(*this);
				++(*this);
				return prev_it;
			}
			reverse_iterator& operator--() {
				if (this->_it == this->_shad || this->_it->right_child != this->_shad)
					this->_it = this->min_node(this->_it->right_child);
				else {
					while (this->_it->parent != this->_shad && this->_it->parent->left_child != this->_it)
						this->_it = this->_it->parent;
					this->_it = this->_it->parent;
				}
				return *this;
			}
			reverse_iterator& operator--(int) {
				reverse_iterator prev_it(*this);
				--(*this);
				return prev_it;
			}
		}				reverse_iterator;

		typedef class const_reverse_iterator : public iterator {
		public:
			const_reverse_iterator() : reverse_iterator(){}
			const_reverse_iterator(node *it, node *shadow) : reverse_iterator(it, shadow){}
			const_reverse_iterator(const reverse_iterator& rhs) : reverse_iterator(rhs){}
			virtual ~const_reverse_iterator(){}
			const value_type &operator*() const{
				return (this->_it->value);
			}
		}				const_reverse_iterator;

		iterator begin() {
			return iterator(this->find_min_key(), _shadow);
		}
		const_iterator begin() const {
			return const_iterator(this->find_min_key(), _shadow);
		}
		reverse_iterator rbegin(){
			return reverse_iterator(this->find_max_key(), _shadow);
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(this->find_max_key(), _shadow);
		}
		iterator end() {
			return iterator (_shadow, _shadow);
		}
		const_iterator end() const {
			return const_iterator(_shadow, _shadow);
		}
		reverse_iterator rend() {
			return reverse_iterator(_shadow, _shadow);
		}
		const_reverse_iterator rend() const {
			return const_reverse_iterator(_shadow, _shadow);
		}

		std::pair<iterator,bool> insert_elem(const value_type& val) {
			node *tmp = _root;
			if (_root == _shadow){
				create_root(val);
				return(std::pair<iterator,bool>(iterator(_root, _shadow), true));
			}
			while(tmp != _shadow){
				if (!_compare(val.first, tmp->value.first) && !_compare(tmp->value.first, val.first))
					return(std::pair<iterator,bool>(iterator(tmp, _shadow), false));
				if (_compare(val.first, tmp->value.first)) {
					if (tmp->left_child == _shadow)
						break;
					tmp = tmp->left_child;
				}
				else {
					if (tmp->right_child == _shadow)
						break;
					tmp = tmp->right_child;
				}
			}
			if (_compare(val.first, tmp->value.first)){
				tmp->left_child = new node(val);
				tmp->left_child->parent = tmp;
				tmp = tmp->left_child;
				tmp->left_child = tmp->right_child = _shadow;
			}
			else{
				tmp->right_child = new node(val);
				tmp->right_child->parent = tmp;
				tmp = tmp->right_child;
				tmp->left_child = tmp->right_child = _shadow;
			}
			_size++;
			return(std::pair<iterator,bool>(iterator(tmp, _shadow), true));
		}

		std::pair<iterator,bool> insert (const value_type& val){
			return this->insert_elem(val);
		}

		iterator insert (iterator position, const value_type& val){
			return this->insert_elem(val).first;
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last){
			while (first != last) {
				this->insert_elem(*first);
				first++;
			}
		}

		void erase (iterator position){
			if (position._it->left_child == _shadow && position._it->right_child == _shadow){
				if (position._it->parent->left_child == position._it)
					position._it->parent->left_child = _shadow;
				else
					position._it->parent->right_child = _shadow;
				if (_root == position._it)
					_root = _shadow;
				delete position._it;
			}
			else if (position._it->left_child == _shadow && position._it->right_child != _shadow){
				if (position._it->parent->left_child == position._it)
					position._it->parent->left_child = position._it->right_child;
				else
					position._it->parent->right_child = position._it->right_child;
				position._it->right_child->parent = position._it->parent;
				if (_root == position._it)
					_root = position._it->right_child;
				delete position._it;
			}
			else if (position._it->left_child != _shadow && position._it->right_child == _shadow){
				if (position._it->parent->left_child == position._it)
					position._it->parent->left_child = position._it->left_child;
				else
					position._it->parent->right_child = position._it->left_child;
				position._it->left_child->parent = position._it->parent;
				if (_root == position._it)
					_root = position._it->left_child;
				delete position._it;
			}
			else{
				node *tmp = position._it->right_child;
				while (tmp->left_child != _shadow)
					tmp = tmp->left_child;
				if (tmp != position._it->right_child)
					tmp->parent->left_child = tmp->right_child;
				tmp->parent = position._it->parent;
				tmp->left_child = position._it->left_child;
				if (tmp != position._it->right_child)
					tmp->right_child = position._it->right_child;
				position._it->left_child->parent = tmp;
				if (tmp != position._it->right_child)
					position._it->right_child->parent = tmp;
				if (position._it->parent->left_child == position._it)
					position._it->parent->left_child = tmp;
				else
					position._it->parent->right_child = tmp;
				if (_root == position._it)
					_root = tmp;
				delete position._it;
			}
			_size--;
		}

		size_type erase (const key_type& k){
			iterator it;
			if ((it = this->find(k)) != this->end()){
				this->erase(it);
				return 1;
			}
			return 0;
		}

		void erase (iterator first, iterator last){
			iterator tmp = first;
			while(tmp != last){
				first = tmp;
				tmp++;
				this->erase(first);
			}
		}

		void swap (map& x){
			node *tmp_node;
			size_type tmp_size;
			Alloc tmp_alloc;
			Compare tmp_comp;

			tmp_node = this->_shadow;
			this->_shadow = x._shadow;
			x._shadow = tmp_node;
			tmp_node = this->_root;
			this->_root = x._root;
			x._root = tmp_node;

			tmp_size = this->_size;
			this->_size = x._size;
			x._size = tmp_size;

			tmp_alloc = this->_alloc;
			this->_alloc = x._alloc;
			x._alloc = tmp_alloc;

			tmp_comp = this->_compare;
			this->_compare = x._compare;
			x._compare = tmp_comp;
		}

		void clear(){
			this->erase(this->begin(), this->end());
		}

		iterator find (const key_type& k){
			node *tmp = _root;
			while(tmp != _shadow){
				if (!_compare(k, tmp->value.first) && !_compare(tmp->value.first, k))
					return iterator(tmp, _shadow);
				else if (_compare(k, tmp->value.first))
					tmp = tmp->left_child;
				else
					tmp = tmp->right_child;
			}
			return this->end();
		}

		size_type count (const key_type& k) const{
			if (this->find(k) != this->end())
				return 1;
			return 0;
		}

		const_iterator find (const key_type& k) const{
			node *tmp = _root;
			while(tmp != _shadow){
				if (!_compare(k, tmp->value.first) && !_compare(tmp->value.first, k))
					return const_iterator(tmp, _shadow);
				else if (_compare(k, tmp->value.first))
					tmp = tmp->left_child;
				else
					tmp = tmp->right_child;
			}
			return this->end();
		}

//		bool operator()( const value_type& lhs, const value_type& rhs ) const{
//			return comp(lhs.first, rhs.first);
//		}

		iterator lower_bound (const key_type& k){
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite) {
				if (_compare(it._it->value.first, k) == false)
					return it;
				it++;
			}
			return this->end();
		}

		const_iterator lower_bound (const key_type& k) const{
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite) {
				if (_compare(it._it->value.first, k) == false)
					return it;
				it++;
			}
			return this->end();
		}

		iterator upper_bound (const key_type& k){
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite) {
				if (_compare(k, it._it->value.first) == true)
					return it;
				it++;
			}
			return this->end();
		}

		const_iterator upper_bound (const key_type& k) const{
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite) {
				if (_compare(k, it._it->value.first) == true)
					return it;
				it++;
			}
			return this->end();
		}

		std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
			return std::pair<const_iterator,const_iterator>(this->lower_bound(k), this->upper_bound(k));
		}

		std::pair<iterator,iterator> equal_range (const key_type& k){
			return std::pair<iterator,iterator>(this->lower_bound(k), this->upper_bound(k));
		}

		allocator_type get_allocator() const{
			return _alloc;
		}

		key_compare key_comp() const{
			return _compare;
		}
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs,
					 const map<Key,T,Compare,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		typename map<Key, T>::const_iterator it_lhs = lhs.begin();
		typename map<Key, T>::const_iterator it_rhs = rhs.begin();
		typename map<Key, T>::const_iterator ite_lhs = lhs.end();
		while (it_lhs != ite_lhs){
			if (*it_lhs != *it_rhs)
				return false;
			it_lhs++;
			it_rhs++;
		}
		return true;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs,
					 const map<Key,T,Compare,Alloc>& rhs ){
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs ){
		typename map<Key, T>::const_iterator it_lhs = lhs.begin();
		typename map<Key, T>::const_iterator it_rhs = rhs.begin();
		typename map<Key, T>::const_iterator ite_lhs = lhs.end();
		typename map<Key, T>::const_iterator ite_rhs = rhs.end();
		while (it_lhs != ite_lhs && it_rhs != ite_rhs){
			if (*it_lhs < *it_rhs)
				return true;
			if (*it_lhs > *it_rhs)
				return false;
			it_lhs++;
			it_rhs++;
		}
		if (it_lhs == ite_lhs && it_rhs != ite_rhs) {
			return true;
		}
		return false;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs,
					 const map<Key,T,Compare,Alloc>& rhs ){
		return (lhs < rhs || lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs ){
		return (rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs,
					 const map<Key,T,Compare,Alloc>& rhs ){
		return (lhs > rhs || lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	void swap(map<Key,T,Compare,Alloc>& lhs,
			  map<Key,T,Compare,Alloc>& rhs ){
		lhs.swap(rhs);
	}
}

#endif