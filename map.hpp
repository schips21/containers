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
	};
}

#endif