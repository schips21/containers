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
//		typedef iterator;
//		typedef const_iterator;
//		typedef reverse_iterator			std::reverse_iterator<iterator>;
//		typedef const_reverse_iterator		std::reverse_iterator<const_iterator>;
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
//			node(key_type key, mapped_type data) : value.first(key), value.second(data){
//			}
			node(const value_type& val) : value(val){
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
//		template <class InputIterator>
//		map (InputIterator first, InputIterator last,
//			 const key_compare& comp = key_compare(),
//			 const allocator_type& alloc = allocator_type()){
//
//		}
//		map (const map& x){
//
//		}
//		~map();

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

		void insert_elem(const value_type& val) {
			node *tmp = _root;
			if (_root == _shadow){
				create_root(val);
				return;
			}
			while(tmp != _shadow){
				//если новое значение меньше
//				std::cout << "TMP " << tmp->value.first << std::endl;
//				std::cout << "VAL " << val.first << std::endl;
//				std::cout << _compare(val.first, tmp->value.first) << std::endl << _compare(val.first, tmp->value.first) << std::endl;
				if (!_compare(val.first, tmp->value.first) && !_compare(tmp->value.first, val.first))
					return;
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

//			tmp = tmp->parent;
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
		}

		node *find_min_key() {
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
			T *operator->() const{
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
			iterator& operator++(int) {
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
			iterator& operator--(int) {
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
		iterator begin() {
			return iterator(this->find_min_key(), _shadow);
		}
		const_iterator begin() const {
			return const_iterator(this->find_min_key(), _shadow);
		}
		iterator end() {
			return iterator (_shadow, _shadow);
		}
		const_iterator end() const {
			return const_iterator(_shadow, _shadow);
		}
	};
}

#endif