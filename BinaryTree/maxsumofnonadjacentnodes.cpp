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

//maximum sum of  non adjacent nodes in a binary tree
int maxsum(node* root){
    if(root==NULL) return 0;
    
    int left = maxsum(root->left);
    int right = maxsum(root->right);

    return max(right+left,root->data);
}

int main(){
    node* root = NULL;
    root = buildTree();
    cout<< maxsum(root);
}