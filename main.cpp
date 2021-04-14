#include "list.hpp"
#include <list>

int main(){
	std::list<int> list_def(3, 10);
	list_def.pop_back();
	list_def.push_front(50);
	list_def.push_front(20);
	list_def.push_front(100);
//	list_def.resize(8,5);
	int h_def;
	int q_def = 0;
	for (std::list<int>::iterator it = list_def.begin(); it != list_def.end(); it++){
		h_def = *it;
		q_def++;
	}

//	std::list<int>::iterator it = list_def.end();
//	h_def = *it;

//	std::list<int>::const_iterator it2 = list_def.begin();
//	std::list<int>::iterator it3 = list_def.end();
//	it2 = it3;

	ft::list<int> list_a(3, 10);
	list_a.pop_back();
	list_a.push_front(50);
	list_a.push_front(20);
	list_a.push_front(100);
	list_a.resize(8,5);
	list_a.push_back(18);
	ft::list<int> list_b;
	list_b.push_front(6);
	list_b.push_front(1);
	ft::list<int>::iterator it = list_b.begin();
	it++;
	ft::list<int>::iterator it1 = list_a.begin();
	it1++;
	it1++;
	ft::list<int>::iterator it2 = it1;
	it2++;
	it2++;
	list_b.insert(it, it1, it2);

	std::cout << list_a.back();
	return 0;
}