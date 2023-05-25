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

// height of the tree
int height(struct node* node){
    if(node == NULL) return 0; //base case
    int lheight = height(node->left);
    int rheight = height(node->right);
    return max(lheight, rheight) + 1;
}


int main(){
    node* root = NULL;
    root = buildTree();
    cout<< height(root);
}