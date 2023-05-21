#include<iostream>
#include<queue>
using namespace std;

// K closest numbers around X
int main(){
    priority_queue < pair<int,int> > maxh; // max heap
    int size=6; 
    int x=5;
    int k=3;    // means 3 numbers closest to 5
    int arr[size] = {6,5,3,2,8,10,9};
    for( int i=0; i<size ; i++){
        maxh.push({abs(arr[i]-x), arr[i]});
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    while(maxh.size()>0){
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }
    return 0;
}

