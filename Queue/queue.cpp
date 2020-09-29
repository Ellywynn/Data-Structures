#include <iostream>

struct MyQueue {
	int maxSize = 100;
	int size = 0;
	int* queue = nullptr;

	void push(int value) {
		if (size <= maxSize) {
			queue[size] = value;
			size++;
		}
		else {
			std::cerr << "Queue overflow! Can't push an element.\n";
		}
	}

	int pop() {
		if (size > 0) {
			int value = queue[size - 1];
			size--;
			return value;
		}
		else {
			std::cerr << "Queue is empty. Nothing to pop out.\n";
		}
	}

	int last() {
		return queue[0];
	}

	int first() {
		return queue[size - 1];
	}

	void info() {
		if (size > 0) {
			std::cout << "There are(is) " << size << " element(s) in the queue.\n";
			std::cout << "The first element: " << first() << "\n";
			std::cout << "The last element: " << last() << "\n";
			std::cout << "Queue:\n";
			for (int i = 0; i < size; i++)
				std::cout << queue[i] << " ";
		}
		else {
			std::cout << "The queue is empty.\n";
		}
		std::cout << "\n";
	}

	MyQueue() {
		queue = new int[maxSize];
	}

	MyQueue(int size) {
		maxSize = size;
		queue = new int[maxSize];
	}
};

int main() {
	//creating 
	MyQueue q(30);

	q.info();
	std::cout << "Pushing elements..\n";
	std::cout << "\n";
	for (int i = 1; i <=30; i++) 
		q.push(i);

	q.info();
	std::cout << "\n";
	std::cout << "Popping the value..\n";

	int val = q.pop();
	std::cout << "val = " << val << "\n";
	std::cout << "\n";
	std::cout << "Queue after pop:\n";
	q.info();
	return 0;
}