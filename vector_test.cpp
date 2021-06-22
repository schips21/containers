#include "vector.hpp"
#include <vector>
#include "tests.hpp"

template <class T>
void print_ft_vec(const ft::vector<T> & vec){
	typename ft::vector<T>::const_iterator it = vec.begin();
	typename ft::vector<T>::const_iterator ite = vec.end();
	std::cout << "FT vector" << std::endl;
	std::cout << "Size " << vec.size() << std::endl;
	std::cout << "Capacity " << vec.capacity() << std::endl;
	while (it != ite){
		std::cout << *it++ << std::endl;
	}
}

template <class T>
void print_std_vec(const std::vector<T> & vec){
	typename std::vector<T>::const_iterator it = vec.begin();
	typename std::vector<T>::const_iterator ite = vec.end();
	std::cout << "STD vector" << std::endl;
	std::cout << "Size " << vec.size() << std::endl;
	std::cout << "Capacity " << vec.capacity() << std::endl;
	while (it != ite){
		std::cout << *it++ << std::endl;
	}
}

void vector_test(){
	std::cout << "---------------------" << std::endl;
	std::cout << "     VECTOR TESTS    " << std::endl;
	std::cout << "---------------------" << std::endl << std::endl;

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;

}