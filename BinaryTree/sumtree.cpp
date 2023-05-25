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

//returns summ of all the nodes in the tree
int sumtree(node* root){
    if(root == NULL) return 0; //base case
    int lsum = sumtree(root->left);
    int rsum = sumtree(root->right);
    return lsum + rsum + root->data;
}

int main(){
    node* root = NULL;
    root = buildTree();
    cout<< sumtree(root);
}