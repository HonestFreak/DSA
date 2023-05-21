#include<iostream>
#include<queue>
using namespace std;

// Kth smallest element
int main(){
    priority_queue < int > pq; // max heap
    int size=6; 
    int k=4;
    int arr[size] = {7,10,4,3,20,15};
    for( int i=0; i<size ; i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    cout<<pq.top();
    return 0;
}

