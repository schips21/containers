#include "list.hpp"
#include <list>

bool my_pred(int data){
	if (data % 2 == 0)
		return true;
	return false;
}

int main(){
	std::list<int> list_def;
	list_def.push_back(1);
	list_def.push_back(2);
	list_def.push_back(3);
	list_def.push_back(4);
	list_def.push_back(5);
	std::list<int>::const_iterator it_d = list_def.begin();
	it_d++; //2
	std::list<int> list_def2;
	list_def2.push_back(10);
	list_def2.push_back(20);
	std::list<int>::const_iterator it2 = list_def2.begin();
	it2++;
	list_def.splice( it_d, list_def2, it2);
//	it_d = list_def.erase(it_d, it_dl);
//	int g = *it_d;

//	std::list<int>::iterator it = list_def.end();
//	h_def = *it;

//	std::list<int>::const_iterator it2 = list_def.begin();
//	std::list<int>::iterator it3 = list_def.end();
//	it2 = it3;

//	ft::list<int> list_a(3, 10);
//	list_a.pop_back();
//	list_a.push_front(50);
//	list_a.push_front(20);
//	list_a.push_front(100);
//	list_a.resize(8,5);
//	list_a.push_back(18);
//	ft::list<int> list_b;
//	list_b.push_front(6);
//	list_b.push_front(1);
//	ft::list<int>::iterator it = list_b.begin();
//	it++;
//	ft::list<int>::iterator it1 = list_a.begin();
//	it1++;
//	it1++;
//	ft::list<int>::iterator it2 = it1;
//	it2++;
//	it2++;
//	list_b.insert(it, it1, it2);


	ft::list<int> list_a;
	ft::list<int> list_b;

	list_a.push_back(1);
	list_a.push_back(9);

	list_b.push_back(5);
	list_b.push_back(5);
	list_b.push_back(10);


	list_a.merge(list_b);
	list_a.unique();
//	list_a.remove_if(my_pred);


//	ft::list<int>::const_iterator it = list_a.begin();
//	it++;
//	ft::list<int>::const_iterator it1 = list_b.begin();
//	it1++;
////	list_a.splice(it, list_b,it1);
////	it = list_a.begin();
////	it1 = list_b.begin();
//	list_a.splice(it, list_b, it1, list_b.end());
////	it = list_b.erase(it, it1);

	std::cout << list_a.back();
	return 0;
}