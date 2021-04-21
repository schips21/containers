#include "list.hpp"
#include <list>
#include "stack.hpp"

bool my_pred(int data){
	if (data % 2 == 0)
		return true;
	return false;
}

int main(){
//	ft::list<int> list_a;
//	ft::list<int> list_b;
//
//	list_a.push_back(1);
//	list_a.push_back(9);
//
//	list_b.push_back(5);
//	list_b.push_back(5);
//	list_b.push_back(10);
//
//	list_b.merge(list_a);
//
//	ft::list<int>::const_iterator it_a = list_a.begin();
//	it_a++;
//	ft::list<int>::const_iterator it_b = list_b.begin();
//	it_b++;
//	ft::list<int>::const_iterator ite_b = list_b.end();
////	list_a.splice(it_a, list_b, it_b, ite_b);
//
//
////	std::cout << list_a.back();

	ft::stack<int> stack;
	stack.push(6);
	stack.push(10);
	stack.push(15);

	ft::stack<int> stack_2;
	stack_2.push(6);
	stack_2.push(10);

	std::cout << (stack <= stack_2) << std::endl;
	return 0;
}