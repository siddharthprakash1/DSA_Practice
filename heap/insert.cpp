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
            //sure that the heap value of current is greater than the heap value of the parent only then perfrom the swap.
                swap(current,parent(current));
                current=parent(current);
            }
        }

        void printHeap(){
            cout<<"\n[";
            for(size_t i=0;i<heap.size();i++){
                cout << heap[i];
                if(i<heap.size()-1){
                    cout<<",";
                }
            }
            cout <<"]"<<endl;
        }
        
};

int main(){
    Heap*myHeap=new Heap();
    myHeap->insert(99);
    myHeap->insert(72);
    myHeap->insert(61);
    myHeap->insert(58);
    myHeap->printHeap();

    myHeap->insert(100);
    myHeap->printHeap();

    myHeap->insert(75);
    myHeap->printHeap();
    
}