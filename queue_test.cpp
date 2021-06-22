#include "queue.hpp"
#include <queue>
#include <unistd.h>

void queue_test(){
	std::cout << "---------------------" << std::endl;
	std::cout << "     QUEUE TESTS     " << std::endl;
	std::cout << "---------------------" << std::endl << std::endl;

	std::queue<char> std_queue_char_one;
	ft::queue<char> ft_queue_char_one;

	std_queue_char_one.push('a');
	std_queue_char_one.push('b');
	std_queue_char_one.push('c');
	ft_queue_char_one.push('a');
	ft_queue_char_one.push('b');
	ft_queue_char_one.push('c');

	std::cout << "Std queue front: " << std_queue_char_one.front() << std::endl;
	std::cout << "Ft queue front: " << ft_queue_char_one.front() << std::endl;
	std::cout << std::endl;

	std::cout << "Std queue back: " << std_queue_char_one.back() << std::endl;
	std::cout << "Ft queue back: " << ft_queue_char_one.back() << std::endl;
	std::cout << std::endl;

	std::cout << "Std queue is empty: " << std_queue_char_one.empty() << std::endl;
	std::cout << "Ft queue is empty: " << ft_queue_char_one.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "Std queue size is: " << std_queue_char_one.size() << std::endl;
	std::cout << "Ft queue size is: " << ft_queue_char_one.size() << std::endl;
	std::cout << std::endl;

	std::queue<char> std_queue_char_two(std_queue_char_one);
	ft::queue<char> ft_queue_char_two(ft_queue_char_one);

	std_queue_char_one.pop();
	ft_queue_char_one.pop();
	std::cout << "Std queue front after pop: " << std_queue_char_one.front() << std::endl;
	std::cout << "Ft queue front after pop: " << ft_queue_char_one.front() << std::endl;
	std::cout << std::endl;

	std::cout << "Std queue ==: " << (std_queue_char_one == std_queue_char_two) << std::endl;
	std::cout << "Ft queue ==: " << (ft_queue_char_one == ft_queue_char_two) << std::endl;
	std::cout << std::endl;

	std::cout << "Std queue !=: " << (std_queue_char_one != std_queue_char_two) << std::endl;
	std::cout << "Ft queue !=: " << (ft_queue_char_one != ft_queue_char_two) << std::endl;
	std::cout << std::endl;

	std::cout << "Std queue <: " << (std_queue_char_one < std_queue_char_two) << std::endl;
	std::cout << "Ft queue <: " << (ft_queue_char_one < ft_queue_char_two) << std::endl;
	std::cout << std::endl;

	std::cout << "Std queue <=: " << (std_queue_char_one <= std_queue_char_two) << std::endl;
	std::cout << "Ft queue <=: " << (ft_queue_char_one <= ft_queue_char_two) << std::endl;
	std::cout << std::endl;

	std::cout << "Std queue >: " << (std_queue_char_one > std_queue_char_two) << std::endl;
	std::cout << "Ft queue >: " << (ft_queue_char_one > ft_queue_char_two) << std::endl;
	std::cout << std::endl;

	std::cout << "Std queue >=: " << (std_queue_char_one >= std_queue_char_two) << std::endl;
	std::cout << "Ft queue >=: " << (ft_queue_char_one >= ft_queue_char_two) << std::endl;
	std::cout << std::endl;
}