#include <iostream>
using namespace std;

int main(){
    int x = 4; 
    int *y = &x;
    int *z;

    cout<<"x ="<<x<<endl; // value of x
    cout<<"y = "<<y<<endl; // value of y i.e. address of x
    cout<<"z = "<<z<<endl; // value of z which is undefined
    cout<<"&x ="<<&x<<endl; // address of x 
    cout<<"*y = "<<*y<<endl; // value at (address of x)
    cout<<"*z = "<<*z<<endl; // undefined
    cout<<"&z ="<<&z<<endl; // address of z
    return 0;
}