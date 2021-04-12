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
//	int h;
//	int q = 0;
//	for (ft::list<int>::const_reverse_iterator it = list_a.rbegin(); it != list_a.rend(); it++){
//		h = *it;
//		q++;
//	}

	std::cout << list_a.back();
	return 0;
}