#include "list.hpp"
#include <list>
#include "stack.hpp"
#include "vector.hpp"
#include <vector>

int main(){

	ft::vector<int> vec(3, 15);
//	for (int i = 0; i < 3; i++){
//		std::cout << vec[i] << std::endl;
//	}
//	vec.delete_vect();
	std::cout << vec.max_size() << std::endl;
	std::vector<int> vec_std(3, 15);
	std::cout << vec_std.max_size() << std::endl;
	return 0;
}