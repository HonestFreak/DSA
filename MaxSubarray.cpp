#include <iostream>
using namespace std;

// maximum subarray problem

int main(){
    int n =6;
    int arr[n] = {-28,13,11,-8,19,3};
    int best = 0, sum = 0;
    for (int k=0; k<n ; k++){
        sum = max(arr[k], sum+arr[k]); // max(1,1) = 1 , max(-32,-31) = -31 , max(3,-28) = 3 , 
                                       // max(6,9) = 9 , max(-34,-25) = -25 , max(8,-17) = 8
        best = max(best,sum);         
    }
    cout<<best<<endl;
}