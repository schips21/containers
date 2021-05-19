#include "list.hpp"
#include <list>
#include "stack.hpp"
#include "vector.hpp"
#include <vector>

int main(){

	ft::vector<int> vec(2, 15);
//	for (int i = 0; i < 3; i++){
//		std::cout << vec[i] << std::endl;
//	}
//	vec.delete_vect();
	std::cout << vec.max_size() << std::endl;
	std::vector<int> vec_std(2, 15);
	std::cout << vec_std.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;
	std::cout << vec_std.capacity() << std::endl;
	vec_std.push_back(7);
	std::cout << vec_std.size() << std::endl;
	std::cout << vec_std.capacity() << std::endl;
	vec.push_back(9);
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;
	return 0;
}