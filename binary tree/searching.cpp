#include<iostream>
using namespace std;

class node {
    public :
        int data;
        node *left;
        node *right;
    
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(){
    int d;
    cin>> d;

    if(d == -1){
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

node* treesearch(node* root,int k){
    if(root==NULL || root->data==k){
        return root;
    }
    if(root->data >k){
        return treesearch(root->left,k);
    }
    else return treesearch(root->right,k);
}

int main()
{
    node* root = NULL;
    root = buildTree();
    int k = 5;
    node* x = treesearch(root,k);
    return 0;
}