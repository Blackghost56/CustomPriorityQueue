#include <iostream>
#include "PriorityQueueCustom.hpp"
#include <vector>

int main(int argc, char** argv)
{
	PriorityQueueCustom<int> queue;

	std::cout << queue.empty() << std::endl;
	std::cout << queue.size() << std::endl;

	std::vector<int> vec = {1, 33, 23, 55};
	std::less<int> c;
	//std::greater<int> c;
	PriorityQueueCustom<int> queue_0(c, vec);
	std::cout << queue_0.size() << std::endl;
	std::cout << queue_0.top() << std::endl;

	// Test pop
	queue_0.pop();
	std::cout << queue_0.top() << std::endl;

	// Test push
	queue_0.push(77);
	const int c_int = 82;
	queue_0.push(c_int);

	// Emplace back
	queue_0.emplace(12, 13, 17);


	system("pause");
	return 0;
}