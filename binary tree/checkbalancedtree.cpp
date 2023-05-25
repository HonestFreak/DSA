#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildtree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

int height(node* node){
    if(node==NULL){
        return 0;
    }
    int lh = height(node->left);
    int rh = height(node->right);
    return max(lh,rh)+1;
}           

// checking if tree is balanced or not
bool isbalanced(node* node){
    if(node==NULL){
        return true;
    }
    if(isbalanced(node->left) && isbalanced(node->right)){
        int lh = height(node->left);
        int rh = height(node->right);
        if(abs(lh-rh)<=1){
            return true;
        }
    }
    return false;
}

int main()
{
  node* root = NULL;
    root = buildtree();
    cout<< isbalanced(root);
 return 0;
}