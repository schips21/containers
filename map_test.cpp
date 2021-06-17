#include "map.hpp"
#include <map>

int main() {
	ft::map<int, int> ft_map;
	ft_map.insert_elem(std::pair<const int, int>(5, 10));
	ft_map.insert_elem(std::pair<const int, int>(3, 11));
	ft_map.insert_elem(std::pair<const int, int>(10, 11));
	ft_map.insert_elem(std::pair<const int, int>(6, 11));
	ft::map<int, int>::reverse_iterator it = ft_map.rend();
	--it;
	std::cout << (*it).first << std::endl;
	--it;

//	std::map<int, int> map;
//	map.insert(std::pair<int, int>(-10, 10));
//	map.insert(std::pair<int, int>(1, 50));
//	std::map<int, int>::iterator it = map.begin();
//	std::cout << it->first << std::endl;
//	map.insert(std::pair<int, int>(-20, 1));
//	it = map.end();
//	std::cout << (--it)->first << std::endl;
	return 0;
}