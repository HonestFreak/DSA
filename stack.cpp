#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(3);
    s.push(10);
    s.push(22);
    s.push(23);

    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
}