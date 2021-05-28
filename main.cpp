#include "list.hpp"
#include <list>
#include "stack.hpp"
#include "vector.hpp"
#include <vector>

int main(){
	ft::vector<int> vec(1, 15);
	std::vector<int> vec_std(1, 15);
	vec_std.push_back(1);
	vec.push_back(1);
	vec_std.push_back(10);
	vec.push_back(10);

	std::vector<int>::iterator it_std = vec_std.begin();
	ft::vector<int>::iterator it = vec.begin();

	std::cout << *it++ << std::endl;
	std::cout << *it << std::endl;

	std::cout << *it_std++ << std::endl;
	std::cout << *it_std << std::endl;
//	*it_std--;
//	std::cout << *it_std << std::endl;
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
