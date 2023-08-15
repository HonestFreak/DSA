#include<iostream>
#include<queue>
using namespace std;

// Sort a k(nearly) sorted array - flipkart
int main(){
    priority_queue < int > maxh; // max heap
    int size=7; 
    int k=3;
    int arr[size] = {6,5,3,2,8,10,9};
    for( int i=0; i<size ; i++){
        maxh.push(arr[i]);
        if(maxh.size()>k){
            cout<<maxh.top()<<" ";
            maxh.pop();
        }
    }
    return 0;
}

