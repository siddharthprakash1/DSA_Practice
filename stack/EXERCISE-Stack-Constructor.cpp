/*
Always make a stack with nullptr pointing out from the bottom most element and not the topmost
look at it as if its a Linked list witht the null ptr pointing out from the bottom most node.
Change the name of the pointer head and tail to top and bottom respectively and u dont even need bottom 
only top pointer is enough.
*/

#include <iostream>

using namespace std;


class Node{
    public:
        int value;
        Node* next;
        Node(int value){
            this->value=value;
            next=nullptr;
        }
};


class Stack {
    /*
    classes are default pvt 
    */
    private:
        Node* top;
        int height;
    public:
        Stack(int value){
            Node* newNode=new Node(value);
            top=newNode;
            height=1;
            
        }
        ~Stack() {
            Node* temp = top;
            while (top) {
                top = top->next;
                delete temp;
                temp = top;
            }
        }

        void printStack() {
            Node* temp = top;
            while (temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getTop() {
            if (top == nullptr) {
                cout << "Top: nullptr" << endl;
            } else {
                cout << "Top: " << top->value << endl;
            }
        }

        void getHeight() {
            cout << "Height: " << height << endl;
        }

};



int main() {
        
    Stack* myStack = new Stack(4);

    myStack->getTop();
    myStack->getHeight();

    cout << "\nStack:\n";
    myStack->printStack();

    /*  
        EXPECTED OUTPUT:
        ----------------
        Top: 4
        Height: 1

        Stack:
        4

    */

}

