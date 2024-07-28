#include<iostream>
#include<vector>
using namespace std;

static int counter = 0;

int fib(int n) {
    vector<int> fiblist;
    fiblist.push_back(0);
    fiblist.push_back(1);
    for(int index = 2; index <= n; index++) {
        counter++;
        fiblist.push_back(fiblist[index-1] + fiblist[index-2]);
    }
    return fiblist[n];
}

int main() {
    int n = 7;
    cout << "\nFib of " << n << " = " << fib(n);
    cout << "\n\nCounter: " << counter << endl;
    return 0;
}

//here but we are not using memoization 
//downside to memoization is code becomes complex and the sapce complexity increases a lot