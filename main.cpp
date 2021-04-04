#include "list.hpp"
#include <list>

int main(){
	std::list<int> list_def(5, 10);

	ft::list<int> list_b;
	ft::list<int> list_a(3, 10);
	list_b.push_back(2);
	return 0;
}