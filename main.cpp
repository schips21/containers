#include "list.hpp"
#include <list>
#include "stack.hpp"
#include "vector.hpp"
#include <vector>

int main(){

	ft::vector<int> vec(2, 15);
	std::cout << vec.max_size() << std::endl;
	std::vector<int> vec_std(2, 15);
	std::cout << vec_std.max_size() << std::endl;
	vec.resize(3);
	vec_std.resize(3);
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;
	std::cout << vec_std.size() << std::endl;
	std::cout << vec_std.capacity() << std::endl;

	std::cout << vec.back() << std::endl;
	std::cout << vec_std.back() << std::endl;
	std::cout << vec.front() << std::endl;
	std::cout << vec_std.front() << std::endl;
	return 0;
}