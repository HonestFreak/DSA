#include<iostream>
#include<queue>
using namespace std;

// K largest element
int main(){
    priority_queue < int , vector<int> , greater<int>> minh; // min heap
    int size=6; 
    int k=4;
    int arr[size] = {7,10,4,3,20,15};
    for( int i=0; i<size ; i++){
        minh.push(arr[i]);
        if(minh.size()>k){
            minh.pop();
        }
    }
    while(!minh.empty()){
        cout<<minh.top()<<" ";
        minh.pop();
    }
    return 0;
}

