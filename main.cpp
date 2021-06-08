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
//	ft::vector<int> vec(1, 15);
//	std::vector<int> vec_std(1, 15);
//	vec_std.push_back(1);
//	vec.push_back(1);
//	vec_std.push_back(10);
//	vec.push_back(10);
//
//	std::vector<int>::iterator it_std = vec_std.end();
//	ft::vector<int>::iterator it = vec.end();
//
//	it--;
//	it_std--;
//
//	std::vector<int>::iterator it_std2;
//	ft::vector<int>::iterator it2;
//	std::cout << std::endl;
//	it_std2 = vec_std.insert(it_std, 20);
//	it2 = vec.insert(it, 20);
//	print_ft_vec(vec);
//	std::cout << *it2 <<std::endl;
//	std::cout << vec.size() << std::endl;
//	std::cout << vec.capacity() << std::endl;
//
//	print_std_vec(vec_std);
//	std::cout << *it_std2 <<std::endl;
//	std::cout << vec_std.size() << std::endl;
//	std::cout << vec_std.capacity() << std::endl;
//
//	it_std = vec_std.end();
//	it = vec.end();


	ft::vector<int> vec(3, 15);
	std::vector<int> vec_std(3, 15);

	vec_std.push_back(1);
	vec.push_back(1);
	vec_std.push_back(10);
	vec.push_back(10);

	std::vector<int>::iterator it_std = vec_std.begin();
	ft::vector<int>::iterator it = vec.begin();

	std::vector<int>::iterator it_std2;
	ft::vector<int>::iterator it2;
	vec_std.insert(++it_std, 2, 20);
	vec.insert(++it, 2, 20);

	print_ft_vec(vec);
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	print_std_vec(vec_std);
	std::cout << vec_std.size() << std::endl;
	std::cout << vec_std.capacity() << std::endl;
}
