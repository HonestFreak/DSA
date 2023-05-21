#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev; //if doubly linked list
};

int main(){
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    one->data = 13;
    one->next = two;
    one->prev = NULL;
    return 0;
}