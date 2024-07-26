// C++ program to find if it is possible to form a triangle 
// from array values 
#include <bits/stdc++.h> 
using namespace std; 

// Method prints possible triangle when array values are 
// taken as sides 
bool isPossibleTriangle(int arr[], int N) 
{ 
	// If number of elements are less than 3, then no 
	// triangle is possible 
	if (N < 3) 
		return false; 
	// first sort the array 
	sort(arr, arr + N); 
	// loop for all 3 consecutive triplets 
	for (int i = 0; i < N - 2; i++) 
		// If triplet satisfies triangle condition, break 
		if (arr[i] + arr[i + 1] > arr[i + 2]) 
			return true; 
	return false; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 5, 4, 3, 1, 2 }; 
	int N = sizeof(arr) / sizeof(int); 

	isPossibleTriangle(arr, N) ? cout << "Yes" : cout << "No"; 
	return 0; 
} 

// This code is contributed by Aditya Kumar (adityakumar129)
