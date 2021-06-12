#include "map.hpp"
#include <map>

int main() {
	ft::map<int, int> ft_map;
	std::cout << ft_map[2] << std::endl;
	ft_map.insert_elem(std::pair<const int, int>(5, 10));
	ft_map.insert_elem(std::pair<const int, int>(4, 11));
	std::cout << ft_map[4] << std::endl;
	std::cout << ft_map[6] << std::endl;
	std::map<int, int> map;
	return 0;
}