#include "list.hpp"
#include <list>

int main(){
	std::list<int> list_def(5, 10);
	std::list<int> list_def_2(3, 7);
	list_def.swap(list_def_2);

	ft::list<int> list_b;
	ft::list<int> list_a(3, 10);
	list_b.push_back(2);
	list_a.pop_back();
	list_a.push_front(50);
	list_a.push_front(20);
	list_a.push_front(100);
	list_a.resize(8,5);
	list_a.swap(list_b);
	return 0;
}