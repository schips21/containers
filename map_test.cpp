#include "map.hpp"
#include <map>

int main() {
	ft::map<int, int> ft_map;
	ft_map.insert_elem(std::pair<const int, int>(5, 10));
	ft_map.insert_elem(std::pair<const int, int>(3, 11));
	ft_map.insert_elem(std::pair<const int, int>(10, 11));
	ft_map.insert_elem(std::pair<const int, int>(6, 11));
	ft::map<int, int> ft_map2(ft_map);

//	std::map<int, int> map;
//	map.insert(std::pair<const int, int>(5, 10));
//	map.insert(std::pair<const int, int>(3, 11));
//	map.insert(std::pair<const int, int>(10, 11));
//	map.insert(std::pair<const int, int>(6, 11));
//	std::map<int, int> map2(map);
	return 0;
}