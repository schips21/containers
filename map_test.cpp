#include "map.hpp"
#include <map>

int main() {
	ft::map<int, int> ft_map;
	ft_map.insert_elem(std::pair<const int, int>(5, 10));
	ft_map.insert_elem(std::pair<const int, int>(4, 11));
	std::map<int, int> map;
}