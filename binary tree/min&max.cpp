#include <iostream>

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

//finding minimum element in a binary tree
int min(node* root){
    while( root->left != NULL){
        root = root->left;
    }
    return root->data; 
}

//finding maximum element in a binary tree
int max(node* root){
    while( root->right != NULL){
        root = root->right;
    }
    return root->data; 
}

int main(){
    node* root = NULL;
    root = buildTree();
    cout<< min(root)<<endl;
    cout<< max(root);
}