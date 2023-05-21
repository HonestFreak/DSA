#include <unordered_map>
#include<queue>
#include<iostream>

using namespace std;

// top K frequent element in an array
// frequncy sort

int main(){
    unordered_map<int,int> m; 
    int size=5; 
    int k=3;   
    int arr[size] = {9,9,1,6,9};
    for( int i=0; i<size ; i++){
        m[arr[i]]++;     
    }

    priority_queue < pair<int, int>> p;
    for(auto i:m){
         p.push({i.first,i.second});
        if(p.size()>k){
            p.pop();
        }
    }
    
     while(p.size()>0){
        cout<<p.top().first<<" ";
        p.pop();
    }
    

    return 0;
}

