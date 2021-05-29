#include "list.hpp"
#include <list>
#include "stack.hpp"
#include "vector.hpp"
#include <vector>

template <class T>
void print_ft_vec(const ft::vector<T> & vec){
	typename ft::vector<T>::const_iterator it = vec.begin();
	typename ft::vector<T>::const_iterator ite = vec.end();
	std::cout << "FT vector" << std::endl;
	while (it != ite){
		std::cout << *it++ << std::endl;
	}
}

template <class T>
void print_std_vec(const std::vector<T> & vec){
	typename std::vector<T>::const_iterator it = vec.begin();
	typename std::vector<T>::const_iterator ite = vec.end();
	std::cout << "STD vector" << std::endl;
	while (it != ite){
		std::cout << *it++ << std::endl;
	}
}

int main(){
	ft::vector<int> vec(1, 15);
	std::vector<int> vec_std(1, 15);
	vec_std.push_back(1);
	vec.push_back(1);
	vec_std.push_back(10);
	vec.push_back(10);

	std::vector<int>::iterator it_std = vec_std.end();
	ft::vector<int>::iterator it = vec.end();

	it-=1;
	std::cout << it[200] << std::endl;

	it_std-=1;
	std::cout << it_std[200] << std::endl;

	ft::vector<int> vec2(vec.begin(), vec.end());
	std::vector<int> vec2_std(vec_std.begin(), vec_std.end());
//	std::cout << *vec2.begin() << std::endl;
//	std::cout << *vec2_std.begin() << std::endl;
//	std::cout << *--vec2.end() << std::endl;
//	std::cout << *--vec2_std.end() << std::endl;
	print_ft_vec(vec2);
	print_std_vec(vec2_std);
}

//int main(){
//
//	ft::vector<int> vec(2, 15);
//	std::cout << vec.max_size() << std::endl;
//	std::vector<int> vec_std(2, 15);
//	std::cout << vec_std.max_size() << std::endl;
//	vec.resize(3);
//	vec_std.resize(3);
//	std::cout << vec.size() << std::endl;
//	std::cout << vec.capacity() << std::endl;
//	std::cout << vec_std.size() << std::endl;
//	std::cout << vec_std.capacity() << std::endl;
//
//	vec.assign(5, 100);
//	vec_std.assign(5, 100);
//	std::cout << "After assign" << std::endl;
//	std::cout << vec.size() << std::endl;
//	std::cout << vec.capacity() << std::endl;
//	std::cout << vec_std.size() << std::endl;
//	std::cout << vec_std.capacity() << std::endl;
//
//	vec.push_back(-1);
//	vec_std.push_back(-1);
//	std::cout << "After push_back" << std::endl;
//	std::cout << vec.size() << std::endl;
//	std::cout << vec.capacity() << std::endl;
//	std::cout << vec_std.size() << std::endl;
//	std::cout << vec_std.capacity() << std::endl;
//
//	ft::vector<int> vec_2(2, 15);
//	std::vector<int> vec_2_std(2, 15);
//	vec.swap(vec_2);
//	vec_std.swap(vec_2_std);
//	std::cout << "After swap" << std::endl;
//	std::cout << vec.size() << std::endl;
//	std::cout << vec.capacity() << std::endl;
//	std::cout << vec_std.size() << std::endl;
//	std::cout << vec_std.capacity() << std::endl;
//
//
//	return 0;
//}
