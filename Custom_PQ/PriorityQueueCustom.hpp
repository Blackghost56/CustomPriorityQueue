#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

template<class T,
	class Container = std::vector<T>,
	class Compare = std::less<typename Container::value_type>
>
class PriorityQueueCustom
{
private:
	Container container_item;
	Compare	compare_item;
public:
	PriorityQueueCustom(const Compare& comp, const Container& ctnr) { 
		compare_item = comp;
		container_item = ctnr;

		std::cout << "before make_heap, v: ";
		for (auto i : container_item) std::cout << i << ' ';
		std::cout << '\n';

		std::make_heap(container_item.begin(), container_item.end(), compare_item);
		
		std::cout << "after make_heap: ";
		for (auto i : container_item) std::cout << i << ' ';
		std::cout << '\n';

		//std::sort_heap(container_item.begin(), container_item.end(), compare_item);
	};
	PriorityQueueCustom() {
		std::make_heap(container_item.begin(), container_item.end(), compare_item);
		//std::sort_heap(container_item.begin(), container_item.end(), compare_item);
	};
	~PriorityQueueCustom() {};

	bool empty() const {
		return container_item.empty();
	};

	std::size_t size() const {
		return container_item.size();
	};

	const T& top() const {
		return container_item.front();
	};

	void pop() {
		// --
		std::cout << "before removing the largest element: ";
		for (auto i : container_item) std::cout << i << ' ';
		std::cout << '\n';
		// --

		std::pop_heap(container_item.begin(), container_item.end());
		container_item.pop_back();

		// --
		std::cout << "after removing the largest element: ";
		for (auto i : container_item) std::cout << i << ' ';
		std::cout << '\n';
		// --
	}

	void push(const T& val) {
		// --
		std::cout << "before push: ";
		for (auto i : container_item) std::cout << i << ' ';
		std::cout << '\n';
		// --
		
		container_item.push_back(val);
		std::make_heap(container_item.begin(), container_item.end(), compare_item);

		// --
		std::cout << "after push: ";
		for (auto i : container_item) std::cout << i << ' ';
		std::cout << '\n';
		// --
	};
	
	void push(T&& val) {
		// --
		std::cout << "before push: ";
		for (auto i : container_item) std::cout << i << ' ';
		std::cout << '\n';
		// --

		container_item.push_back(val);
		std::make_heap(container_item.begin(), container_item.end(), compare_item);

		// --
		std::cout << "after push: ";
		for (auto i : container_item) std::cout << i << ' ';
		std::cout << '\n';
		// --
	};

	template <class... Args> void emplace(Args&&... args) {
		// --
		std::cout << "before emplace_back: ";
		for (auto i : container_item) std::cout << i << ' ';
		std::cout << '\n';
		// --

		container_item.emplace_back(args);
		std::push_heap(container_item.begin(), container_item.end(), compare_item);

		// --
		std::cout << "after emplace_back: ";
		for (auto i : container_item) std::cout << i << ' ';
		std::cout << '\n';
		// --
	};
};