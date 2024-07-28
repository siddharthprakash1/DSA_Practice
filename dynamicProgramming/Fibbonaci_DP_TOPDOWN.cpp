#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> memo(100,-1);
static int counter=0;

int fib(int n){
    counter ++;
    if(memo[n] != -1){
        return memo[n];
    }
    if(n==0||n==1){
        return n;
    }
    //not here that for index 0 and 1 the value is returned it not stored on the vecotr memo
    //so at the index 0 and 1 its still gonna be -1 and not 0 and 1 
    memo[n]=fib(n-2)+fib(n-1);
    return memo[n];
}

int main(){
    int n=41;
    cout<< "\nFib of "<<n<<"="<<fib(n);
    cout<<"\n\nCounter:"<<counter<<endl;
}