#include<iostream>
#include<vector>
#include<climits>

using namespace std;
//helper functions to insert into a heap
class Heap{
    private:
        vector<int> heap;

        int leftChild(int index){
            return 2* index+1;//since here the array is starting from zero not 1
        }

        int rightChild(int index){
            return 2* index +2; //since here the array is starting from zero not 1
        }
        int parent(int index){
            return(index-1)/2;
        }
        void swap(int index1,int index2){
            int temp= heap[index1];
            heap[index1]=heap[index2];
            heap[index2]=temp;
        }
    public:
        void insert(int value){
            heap.push_back(value);//this will add the value to the end of the heap
            int current=heap.size()-1;
            while (current>0 && heap[current]>heap[parent(current)]){ //dumb fuck the heap[current] give the value at the heap and make
            //sure that the heap
                swap(current,parent(current));
                current=parent(current);
            }
        }
        
};