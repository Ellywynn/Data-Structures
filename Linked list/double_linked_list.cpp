#include <iostream>

struct Node {
	int value;
	Node* next;
	Node* prev;
};

struct DoubleList {

	void addEnd(int val) {
		Node* temp = new Node;
		temp->next = nullptr;
		temp->prev = nullptr;
		temp->value = val;

		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			temp->prev = tail;
			tail->next = temp;
			tail = tail->next;
		}
	}

	void addMiddle(int value, Node* before) {
		Node* temp = new Node;
		temp->value = value;
		temp->next = before->next;
		temp->prev = before;
		before->next = temp;
	}

	void addFront(int value) {
		Node* temp = new Node;
		temp->value = value;
		temp->next = head;
		temp->prev = nullptr;
		head = temp;
	}

	Node* findNode(int value) {
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->value == value) {
				return temp;
			}
			else {
				temp = temp->next;
			}
		}
	}

	void display() {
		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->value << " ";
			temp = temp->next;
		}
		std::cout << "\n";
	}

	void deleteNode(int value) {
		Node* deleted = findNode(value);
		deleted->prev->next = deleted->next;
		deleted->next->prev = deleted->prev;
		delete deleted;
	}
private:
	Node* head = nullptr;
	Node* tail = nullptr;
};

int main() {
	DoubleList l;

	std::cout << "Pushing elements..\n\n";

	for (int i = 1; i <= 10; i++)
		l.addEnd(i);

	std::cout << "List after initialization:\n";
	l.display(); //1 2 3 4 5 6 7 8 9 10

	std::cout << "\nAdding elements in front..\n\n";
	l.addFront(0);
	l.addFront(-1);
	
	std::cout << "List after pushing in front:\n";
	l.display(); //-1 0 1 2 3 4 5 6 7 8 9 10

	std::cout << "\nPushing element in the middle..\n\n";
	l.addMiddle(200, l.findNode(7));

	std::cout << "List after pushing in the middle:\n";
	l.display(); //-1 0 1 2 3 4 5 6 7 200 8 9 10

	std::cout << "Deleting element..\n\n";
	l.deleteNode(7);

	std::cout << "List after deleting element:\n";
	l.display(); //-1 0 1 2 3 4 5 6 200 8 9 10
	return 0;
}