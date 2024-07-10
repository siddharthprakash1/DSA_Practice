#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool itemInCommon(vector<int> vect1, vector <int> vect2){
    for(auto i : vect1){
        for(auto j :vect2){
            if(i==j){
                return true;
            }
        }
    }
    return false;
}

//here the time complexity is o(n^2)

bool itemInCommonHash(vector<int> vect1, vector <int> vect2){
    unordered_map<int,bool> myMap;
    for(auto i :vect1){
        myMap.insert({i,true});
    }
    for(auto j: vect2){
        if(myMap[j]) return true;
    }
    return false;
}

//here the time complexity is o(2n) or o(n)
int main(){
    vector<int> vect1{1,3,5};
    vector<int> vect2{2,4,5};
    cout<<itemInCommonHash(vect1,vect2);
}