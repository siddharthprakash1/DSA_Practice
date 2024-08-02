#include <iostream>

using namespace std;

class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    
        ~DoublyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty" << endl;
                return;
            }
            while (temp->next != nullptr) {
                cout << temp->value << " <-> ";
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    
        Node* getHead() {
            return head;
        }
    
        Node* getTail() {
            return tail;
        }
    
        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }
            /*
            bool isPalindrome() {
            if (length == 0) {
                return false;
            } 
            if (length == 1) {
                return true;
            }
            vector<int> f;
            vector<int> l;
            Node* temp = head;
            while (temp != nullptr) {
                f.push_back(temp->value);
                temp = temp->next;
            }
            temp = tail;
            while (temp != nullptr) {
                l.push_back(temp->value);
                temp = temp->prev;
            }
            return f == l;
        }
        This is my vector approach Gives answer but is ineffecient uses O(3n) which is O(n) and has high space complexity as well 
        */
        //Below is the 2 pointer approach
        

};


