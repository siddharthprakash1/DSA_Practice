#include <iostream>

using namespace std;


	// CREATE INSERTIONSORT FUNCTION HERE //
	//                                    //
	//                                    //
	//                                    //
	//                                    //
	////////////////////////////////////////
    void insertionSort(int array[],int size){
        
    }



int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    insertionSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}

