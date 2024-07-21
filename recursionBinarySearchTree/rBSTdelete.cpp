#include <iostream>
#include <queue>

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
public:
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
    
    Node* rInsert(Node* currentNode, int value) {
        if (currentNode == nullptr) return new Node(value);
    
        if (value < currentNode->value) {
            currentNode->left = rInsert(currentNode->left, value);
        } else if (value > currentNode->value) {
            currentNode->right = rInsert(currentNode->right, value);
        } 
        return currentNode;
    }

    void rInsert(int value) { 
        if (root == nullptr) root = new Node(value);
        else rInsert(root, value); 
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

    int minValue(Node* currentNode) {
        while (currentNode->left != nullptr) {
            currentNode = currentNode->left;
        }
        return currentNode->value;
    } 
          
    Node* deleteNode(Node* currentNode, int value) {
        if (currentNode == nullptr) return nullptr;
        
        if (value < currentNode->value) {
            currentNode->left = deleteNode(currentNode->left, value);
        }
        else if (value > currentNode->value) {
            currentNode->right = deleteNode(currentNode->right, value);
        }
        else {
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                delete currentNode;
                return nullptr;
            }
            else if (currentNode->left == nullptr) {
                Node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr) {
                Node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }
            else {
                int x = minValue(currentNode->right);
                currentNode->value = x;
                currentNode->right = deleteNode(currentNode->right, x);
            }
        }
        return currentNode;
    }

    void deleteNode(int value) { root = deleteNode(root, value); }

    // Function to print the tree structure
    void printTree() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                Node* node = q.front();
                q.pop();
                if (node == nullptr) {
                    cout << "N ";
                } else {
                    cout << node->value << " ";
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

void test() {
    // Test: Delete Node from an Empty Tree
    {
        cout << "\n----- Test: Delete Node from Empty Tree -----\n";
        BinarySearchTree bst;
        bst.deleteNode(42); // Attempt to delete from an empty tree
        cout << "Attempting to delete value 42 from an empty tree.\n";
        cout << (bst.getRoot() == nullptr ? "PASS\n" : "FAIL\n");
        bst.printTree();
    }

    // Test: Delete Leaf Node
    {
        cout << "\n----- Test: Delete Leaf Node -----\n";
        BinarySearchTree bst;
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        bst.rInsert(20); // Leaf node
        cout << "Tree before deletion:" << endl;
        bst.printTree();
        bst.deleteNode(20); // Deleting the leaf node
        cout << "Tree after deleting leaf node 20:" << endl;
        bst.printTree();
        cout << "Deleting leaf node 20.\n";
        cout << (!bst.rContains(20) ? "PASS\n" : "FAIL\n");
    }

    // Test: Delete Node with One Child
    {
        cout << "\n----- Test: Delete Node with One Child -----\n";
        BinarySearchTree bst;
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        bst.rInsert(20);
        bst.rInsert(25); // Node with one child
        cout << "Tree before deletion:" << endl;
        bst.printTree();
        bst.deleteNode(20); // Deleting node with one child
        cout << "Tree after deleting node 20 (which has one child 25):" << endl;
        bst.printTree();
        cout << "Deleting node 20, which has one child 25.\n";
        cout << (!bst.rContains(20) && bst.rContains(25) ? "PASS\n" : "FAIL\n");
    }

    // Test: Delete Node with Two Children
    {
        cout << "\n----- Test: Delete Node with Two Children -----\n";
        BinarySearchTree bst;
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        bst.rInsert(20);
        bst.rInsert(40);
        bst.rInsert(60);
        bst.rInsert(80);
        cout << "Tree before deletion:" << endl;
        bst.printTree();
        bst.deleteNode(30); // Node with two children
        cout << "Tree after deleting node 30 (which has two children):" << endl;
        bst.printTree();
        cout << "Deleting node 30, which has two children (20 and 40).\n";
        cout << (!bst.rContains(30) && bst.rContains(20) && bst.rContains(40) ? "PASS\n" : "FAIL\n");
    }

    // Test: Delete Root Node
    {
        cout << "\n----- Test: Delete Root Node -----\n";
        BinarySearchTree bst;
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        cout << "Tree before deletion:" << endl;
        bst.printTree();
        bst.deleteNode(50); // Deleting the root node
        cout << "Tree after deleting root node 50:" << endl;
        bst.printTree();
        cout << "Deleting root node 50.\n";
        cout << (!bst.rContains(50) ? "PASS\n" : "FAIL\n");
    }
}

int main() {
    test();
    return 0;
}