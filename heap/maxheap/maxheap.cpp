#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

class Heap {
    private:
        vector<int> heap;

        int leftChild(int index) {
            return 2 * index + 1;
        }

        int rightChild(int index) {
            return 2 * index + 2;
        }

        int parent(int index) {
            return (index - 1) / 2;
        }

        void swap(int index1, int index2) {
            int temp = heap[index1];
            heap[index1] = heap[index2];
            heap[index2] = temp;
        }

    public:
        void printHeap() {
            cout << "\n[";
            for (size_t i = 0; i < heap.size(); i++) {
                cout << heap[i];
                if (i < heap.size() - 1) { 
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
        
        const vector<int>& getHeap() const {
            return heap;
        }

        //   +===================================================+
        //   |              WRITE YOUR CODE HERE                 |
        //   | Description:                                      |
        //   | - Inserts a new value into the heap.              |
        //   | - Maintains the heap's property by ensuring the   |
        //   |   newly inserted element is moved to its          |
        //   |   correct position in the heap.                   |
        //   |                                                   |
        //   | Parameters:                                       |
        //   | - value: The value to be inserted into the heap.  |
        //   |                                                   |
        //   | Behavior:                                         |
        //   | - The value is added to the end of the heap.      |
        //   | - The method then compares the added value with   |
        //   |   its parent node, swapping them if necessary to  |
        //   |   maintain the heap property.                     |
        //   | - This comparison and potential swap continue     |
        //   |   until the heap property is restored or the      |
        //   |   added node becomes the root of the heap.        |
        //   +===================================================+

};

