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
        void sinkDown(int index){ //here the we can write nothing int index but we are writing as later it will be used in other funtion 
            int maxIndex=index;
            while(true){
                int leftIndex=leftChild(index);
                int rightIndex=rightChild(index);
                if(heap[leftIndex]>heap[maxIndex] && heap[leftIndex]> heap[maxIndex]){
                    maxIndex=leftIndex;
                }
                if(rightIndex<heap.size() && heap[rightIndex]>heap[maxIndex]){
                    maxIndex=rightIndex;
                }
                if(maxIndex != index){
                    swap(index,maxIndex);
                    index=maxIndex;
                }else{
                    return;
                }
            }
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
        
        int remove(){
            if(heap.empty()){ //when the number of values is 0
                return INT_MIN;
            }
            //doesnot matter how many values in the heap you will always return the head of the heap
            int maxValue=heap.front();
            if(heap.size()==1){
                heap.pop_back();
            }else{
                heap[0]=heap.back();//this will return the end of the value of the heap and make it the new head
                heap.pop_back();//will remove the last value as it is the head now
                sinkDown(0);
            }
            return maxValue;
        }
        
};

int main(){
    Heap*myHeap=new Heap();
    myHeap->insert(95);
    myHeap->insert(75);
    myHeap->insert(80);
    myHeap->insert(55);
    myHeap->insert(60);
    myHeap->insert(50);
    myHeap->insert(65);
    myHeap->printHeap();

    myHeap->remove();
    myHeap->printHeap();

    myHeap->remove();
    myHeap->printHeap();
    
}