#include <iostream>

using namespace std;

class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree {
    private:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }

        void destroy(Node* currentNode) {
            if (currentNode == nullptr) return;
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }

        Node* getRoot() {
            return root;
        }   
        
        bool rContains(Node* currentNode, int value) {
            if (currentNode == nullptr) return false;
            
            if (currentNode->value == value) return true;
            
            if (value < currentNode->value) {
                return rContains(currentNode->left, value);
            } else {
                return rContains(currentNode->right, value);
            }
        }
        bool rContains(int value) { 
            return rContains(root, value); 
        } 

        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }
               
        Node* rInsert(Node* currentNode, int value) {
            if (currentNode == nullptr) return new Node(value);
            if (value < currentNode->value) {
                currentNode->left = rInsert(currentNode->left, value);
            }
            else if (value > currentNode->value) {
                currentNode->right = rInsert(currentNode->right, value);
            }
            return currentNode;
        }
        
        void rInsert(int value) { 
            if (root == nullptr) root = new Node(value);
            rInsert(root, value); 
        } 
};

static void test() {
    {
        cout << "\n----- Test: rInsert into Empty Tree -----\n";
        BinarySearchTree bst;
        int valueToInsert = 42;
        bst.rInsert(valueToInsert);
        cout << "Inserting value " << valueToInsert << " into an empty tree.\n";
        cout << "EXPECTED: Node with value 42 exists\n";
        cout << (bst.rContains(42) ? "PASS\n" : "FAIL\n");
    }
    {
        cout << "\n----- Test: rInsert Unique Values -----\n";
        BinarySearchTree bst;
        bst.rInsert(10);
        bst.rInsert(5);
        bst.rInsert(15);
        cout << "Inserting unique values 10, 5, 15.\n";
        cout << "EXPECTED: Each value is contained within the tree\n";
        cout << (bst.rContains(10) && bst.rContains(5) && bst.rContains(15) ? "PASS\n" : "FAIL\n");
    }
    {
        cout << "\n----- Test: rInsert Duplicate Value -----\n";
        BinarySearchTree bst;
        bst.rInsert(10);
        bst.rInsert(10); // Attempting duplicate insert
        cout << "Inserting value 10 twice.\n";
        cout << "EXPECTED: Tree structure unchanged by duplicate insert\n";
        cout << (bst.rContains(10) ? "PASS\n" : "FAIL\n");
    }
    {
        cout << "\n----- Test: rInsert to Form Complex Structure -----\n";
        BinarySearchTree bst;
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        bst.rInsert(20);
        bst.rInsert(40);
        bst.rInsert(60);
        bst.rInsert(80);
        cout << "Inserting values to form a complex tree structure.\n";
        cout << "EXPECTED: All inserted values are correctly contained within the tree\n";
        cout << (bst.rContains(50) && bst.rContains(30) && bst.rContains(70) &&
                 bst.rContains(20) && bst.rContains(40) && bst.rContains(60) &&
                 bst.rContains(80) ? "PASS\n" : "FAIL\n");
    }
}

int main() {
    test();
    return 0;
}