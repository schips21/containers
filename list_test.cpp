#include "list.hpp"
#include <list>
#include <unistd.h>
#include "tests.hpp"

template <class T>
void print_std_list(std::list<T> & list){
	typename std::list<T>::const_iterator it = list.begin();
	typename std::list<T>::const_iterator ite = list.end();

	while (it != ite){
		std::cout << *it;
		if (++it != ite)
			std::cout <<" ";
	}
	std::cout << std::endl;
}

template <class T>
void print_ft_list(ft::list<T> & list){
	typename ft::list<T>::const_iterator it = list.begin();
	typename ft::list<T>::const_iterator ite = list.end();

	while (it != ite){
		std::cout << *it;
		if (++it != ite)
			std::cout <<" ";
	}
	std::cout << std::endl;
}

bool my_cmp(const int &a, const int &b){
	if (a < b)
		return true;
	return false;
}

bool my_pred(int data){
	if (data % 2 == 0)
		return true;
	return false;
}

void list_test(){
	std::cout << "---------------------" << std::endl;
	std::cout << "      LIST TESTS     " << std::endl;
	std::cout << "---------------------" << std::endl << std::endl;

	std::list<int> std_list_int_one(5, 15);
	ft::list<int> ft_list_int_one(5, 15);

	std::cout << "Std list: \n";
	print_std_list(std_list_int_one);
	std::cout << "Ft list: \n";
	print_ft_list(ft_list_int_one);
	std::cout << std::endl;

	std_list_int_one.push_back(1);
	std_list_int_one.push_front(20);
	ft_list_int_one.push_back(1);
	ft_list_int_one.push_front(20);

	std::cout << "Std list after pushback 1 and pushfront 20: \n";
	print_std_list(std_list_int_one);
	std::cout << "Ft list after pushback 1 and pushfront 20: \n";
	print_ft_list(ft_list_int_one);
	std::cout << std::endl;

	std::cout << "Std list empty test: \n";
	if (std_list_int_one.empty())
		std::cout << "Std list is empty\n";
	if (!std_list_int_one.empty())
		std::cout << "Std list is not empty\n";
	std::cout << "Ft list empty test: \n";
	if (std_list_int_one.empty())
		std::cout << "Std list is empty\n";
	if (!std_list_int_one.empty())
		std::cout << "Std list is not empty\n";
	std::cout << std::endl;

	std::cout << "Std list size is: ";
	std::cout << std_list_int_one.size() << std::endl;
	std::cout << "Ft list size is: ";
	std::cout << ft_list_int_one.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Std list max size is: ";
	std::cout << std_list_int_one.max_size() << std::endl;
	std::cout << "Ft list max size is: ";
	std::cout << ft_list_int_one.max_size() << std::endl;
	std::cout << std::endl;

	std::list<int>::const_iterator std_it = std_list_int_one.begin();
	std::list<int>::const_iterator std_ite = std_list_int_one.end();
	std_ite--;
	std_ite--;

	ft::list<int>::const_iterator ft_it = ft_list_int_one.begin();
	ft::list<int>::const_iterator ft_ite = ft_list_int_one.end();
	ft_ite--;
	ft_ite--;

	std::list<int> std_list_int_two(std_it, std_ite);
	ft::list<int> ft_list_int_two(ft_it, ft_ite);

	std::cout << "Std list two constructed from list one with iterators: \n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two constructed from list one with iterators: \n";
	print_ft_list(ft_list_int_two);
	std::cout << std::endl;

	std_list_int_one.clear();
	ft_list_int_one.clear();
	std::cout << "Std list one size after clear function is: ";
	std::cout << std_list_int_one.size() << std::endl;
	std::cout << "Ft list one size after clear function is: ";
	std::cout << ft_list_int_one.size() << std::endl;
	std::cout << std::endl;

	std::list<int>::iterator std_nonconst_it = std_list_int_two.begin();
	std_nonconst_it++;
	ft::list<int>::iterator ft_nonconst_it = ft_list_int_two.begin();
	ft_nonconst_it++;
	std_list_int_two.insert(std_nonconst_it, 2);
	ft_list_int_two.insert(ft_nonconst_it, 2);
	std::cout << "Std list two after insert function is:\n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two after insert function is:\n";
	print_ft_list(ft_list_int_two);
	std::cout << std::endl;

	std::list<int>::iterator std_nonconst_it_one = std_list_int_one.begin();
	ft::list<int>::iterator ft_nonconst_it_one = ft_list_int_one.begin();
	std_nonconst_it = std_list_int_two.begin();
	std_nonconst_it++;
	ft_nonconst_it = ft_list_int_two.begin();
	ft_nonconst_it++;
	std_list_int_one.insert(std_nonconst_it_one, std_nonconst_it, --std_list_int_two.end());
	ft_list_int_one.insert(ft_nonconst_it_one, ft_nonconst_it, --ft_list_int_two.end());
	std::cout << "Std list one after insert function from list two is:\n";
	print_std_list(std_list_int_one);
	std::cout << "Ft list one after insert function from list two is:\n";
	print_ft_list(ft_list_int_one);
	std::cout << std::endl;

	std_nonconst_it = std_list_int_two.begin();
	std_nonconst_it++;
	ft_nonconst_it = ft_list_int_two.begin();
	ft_nonconst_it++;
	std_list_int_two.erase(++std_nonconst_it);
	ft_list_int_two.erase(++ft_nonconst_it);
	std::cout << "Std list two after erase function:\n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two after erase function:\n";
	print_ft_list(ft_list_int_two);
	std::cout << std::endl;

	std_list_int_two.pop_back();
	ft_list_int_two.pop_back();
	std::cout << "Std list two after pop_back function:\n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two after pop_back function:\n";
	print_ft_list(ft_list_int_two);
	std::cout << std::endl;

	std_list_int_two.pop_front();
	ft_list_int_two.pop_front();
	std::cout << "Std list two after pop_front function:\n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two after pop_front function:\n";
	print_ft_list(ft_list_int_two);
	std::cout << std::endl;

	std_list_int_two.resize(6, 1);
	ft_list_int_two.resize(6, 1);
	std::cout << "Std list two after resize function:\n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two after resize function:\n";
	print_ft_list(ft_list_int_two);
	std::cout << std::endl;

	std::cout << "Std lists before swap function:\n";
	std::cout << "Std list one: ";
	print_std_list(std_list_int_one);
	std::cout << "Std list two: ";
	print_std_list(std_list_int_two);
	std_list_int_one.swap(std_list_int_two);
	std::cout << "Std lists after swap function:\n";
	std::cout << "Std list one: ";
	print_std_list(std_list_int_one);
	std::cout << "Std list two: ";
	print_std_list(std_list_int_two);
	std::cout << std::endl;

	std::cout << "Ft lists before swap function:\n";
	std::cout << "Ft list one: ";
	print_ft_list(ft_list_int_one);
	std::cout << "Ft list two: ";
	print_ft_list(ft_list_int_two);
	ft_list_int_one.swap(ft_list_int_two);
	std::cout << "Ft lists after swap function:\n";
	std::cout << "Ft list one: ";
	print_ft_list(ft_list_int_one);
	std::cout << "Std list two: ";
	print_ft_list(ft_list_int_two);
	std::cout << std::endl;

	std_list_int_one.clear();
	std_list_int_two.clear();
	std_list_int_one.push_back(5);
	std_list_int_one.push_back(12);
	std_list_int_one.push_back(18);
	std_list_int_one.push_back(3);
	std_list_int_one.push_back(-20);
	std_list_int_one.push_back(1);

	std_list_int_two.push_back(4);
	std_list_int_two.push_back(6);
	std_list_int_two.push_back(-3);
	std::cout << "New Std lists:\n";
	std::cout << "Std list one: ";
	print_std_list(std_list_int_one);
	std::cout << "Std list two: ";
	print_std_list(std_list_int_two);

	ft_list_int_one.clear();
	ft_list_int_two.clear();
	ft_list_int_one.push_back(5);
	ft_list_int_one.push_back(12);
	ft_list_int_one.push_back(18);
	ft_list_int_one.push_back(3);
	ft_list_int_one.push_back(-20);
	ft_list_int_one.push_back(1);

	ft_list_int_two.push_back(4);
	ft_list_int_two.push_back(6);
	ft_list_int_two.push_back(-3);
	std::cout << "New Ft lists:\n";
	std::cout << "Ft list one: ";
	print_ft_list(ft_list_int_one);
	std::cout << "Ft list two: ";
	print_ft_list(ft_list_int_two);

	std_list_int_one.merge(std_list_int_two, my_cmp);
	ft_list_int_one.merge(ft_list_int_two, my_cmp);
	std::cout << "Std list one after merge function:\n";
	print_std_list(std_list_int_one);
	std::cout << "Ft list one after merge function:\n";
	print_ft_list(ft_list_int_one);


	std_it = std_list_int_one.begin();
	std_it++;
	std_ite = std_it;
	std_ite++;
	std_ite++;
	std_ite++;
	std_list_int_two.splice(std_list_int_two.begin(), std_list_int_one);
	ft_it = ft_list_int_one.begin();
	ft_it++;
	ft_ite = ft_it;
	ft_ite++;
	ft_ite++;
	ft_ite++;
	ft_list_int_two.splice(ft_list_int_two.begin(), ft_list_int_one);
	std::cout << "Std list two after splice function:\n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two after splice function:\n";
	print_ft_list(ft_list_int_two);

	std_list_int_two.remove_if(my_pred);
	ft_list_int_two.remove_if(my_pred);
	std::cout << "Std list two after remove function:\n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two after remove function:\n";
	print_ft_list(ft_list_int_two);

	std_list_int_two.reverse();
	ft_list_int_two.reverse();
	std::cout << "Std list two after reverse function:\n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two after reverse function:\n";
	print_ft_list(ft_list_int_two);
	std::cout << std::endl;

	std_list_int_two.push_back(5);
	std_list_int_two.push_back(2);
	std_list_int_two.push_back(1);
	ft_list_int_two.push_back(5);
	ft_list_int_two.push_back(2);
	ft_list_int_two.push_back(1);
	std::cout << "Std list two before unique function:\n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two before unique function:\n";
	print_ft_list(ft_list_int_two);
	std::cout << std::endl;

	std_list_int_two.unique();
	ft_list_int_two.unique();
	std::cout << "Std list two after unique function:\n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two after unique function:\n";
	print_ft_list(ft_list_int_two);

	std_list_int_two.sort();
	ft_list_int_two.sort();
	std::cout << "Std list two after sort function:\n";
	print_std_list(std_list_int_two);
	std::cout << "Ft list two after sort function:\n";
	print_ft_list(ft_list_int_two);
	std::cout << std::endl;
}