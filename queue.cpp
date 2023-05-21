#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(10);
    q.push(34);
    q.push(300);
    q.push(12);

    cout<<q.back()<<endl;
    cout<<q.front()<<endl;
    q.pop();    // removes the element from front of the queue
    cout<<q.back()<<endl; // so no effect to back
    cout<<q.front()<<endl;

    return 0;
}