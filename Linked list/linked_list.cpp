#include <iostream>

struct Node {
    int data;
    Node* next;
};

struct MyLinkedList {

    // a -> b -> c ==> a -> b -> c -> d
    void addEnd(int data) {
        Node* temp = new Node;
        temp->data = data;
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {  
            tail->next = temp;
            tail = tail->next;
        }
    }

    // b -> c ->  ==> a -> b -> c
    void addFront(int data) {
        Node* temp = new Node;
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    //a -> c  ==> a -> b -> c
    void addMiddle(Node* node, int data) {
        Node* temp = new Node;
        temp->data = data;
        temp->next = node->next;
        node->next = temp;
    }

    
    //a -> b -> c   ==>  a -> c
    void deleteNode(int data) {
        Node* temp = nullptr;
        Node* before = findNodeBefore(data);
        if (before == head) {
            head = before->next;
            delete before;
        }
        else {
            temp = before->next;
            before->next = temp->next;
        }
        delete temp;
    }

    Node* findNode(int data) {
        Node* temp = head;
        while (true) {
            if (temp->next == nullptr) {
                std::cout << "There is no node with this data.\n";
                return nullptr;
            }
            else {
                if (temp->data == data) {
                    return temp;
                }
                else {
                    temp = temp->next;
                }
            }
        }
    }

    // needs to delete node cause we need to link node bofore to node after deleted node
    // a -> b -> c  ==> a -> c
    Node* findNodeBefore(int data) {
        Node* temp = head;
        Node* before = temp;
        while (true) {
            if (temp == nullptr) {
                std::cout << "There is no node with this data.\n";
                return nullptr;
            }
            else {
                if (temp->data == data) {
                    return before;
                }
                else {
                    before = temp;
                    temp = temp->next;
                }
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data;
            if (temp->next != nullptr) std::cout << "-";
            temp = temp->next;
        }
        std::cout << "\n";
    }

private:
    Node* head = nullptr;
    Node* tail = nullptr;
};

int main()
{
    MyLinkedList list;
    list.addEnd(10);
    list.addEnd(20);
    list.addEnd(30);

    std::cout << "ListNode after initialization:\n";
    list.display(); //10-20-30

    list.addFront(1);
    list.addFront(2);
    
    std::cout << "ListNode after front adding:\n";
    list.display(); //2-1-10-20-30

    list.addMiddle(list.findNode(10), 15);
    list.addMiddle(list.findNode(15), 17);

    std::cout << "ListNode after middle adding:\n";
    list.display(); //2-1-10-15-17-20-30

    std::cout << "\nDeleting nodes...\n\n";
    list.deleteNode(2);
    list.deleteNode(15);

    std::cout << "ListNode after deleting:\n";
    list.display(); //1-10-17-20-30
    return 0;
}