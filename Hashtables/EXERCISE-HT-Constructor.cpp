#include <iostream>

using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

//if you have prime numbers you will have lesser collision 

class HashTable {
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];

public:
    HashTable() {
        for(int i = 0; i < SIZE; i++) {
            dataMap[i] = nullptr;
        }
    }

    ~HashTable() {
        for(int i = 0; i < SIZE; i++) {
            Node* head = dataMap[i];
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    }

    void printTable() {
        for(int i = 0; i < SIZE; i++) {
            cout << i << ":" << endl;
            if(dataMap[i]) {
                Node* temp = dataMap[i];
                while (temp) {
                    cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                    temp = temp->next;
                }
            }
        }
    }
};

int main() {
    HashTable* myHashTable = new HashTable();

    cout << "Hash Table: \n";
    myHashTable->printTable();

    /*
        EXPECTED OUTPUT:
        ----------------
        Hash Table: 
        0:
        1:
        2:
        3:
        4:
        5:
        6:
    */  

    delete myHashTable;
    return 0;
}
