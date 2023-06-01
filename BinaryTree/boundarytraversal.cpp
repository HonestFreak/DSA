#include <iostream>
#include <vector>

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

void lefttraversal(node* root, vector<int> &ans){
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return ;
    ans.push_back(root->data);    
    if(root->left->data != NULL)
    lefttraversal(root->left, ans);
    else
    lefttraversal(root->right, ans);
}

void righttraversal(node* root, vector<int> &ans){
    if(root==NULL ||( root->left==NULL && root->right==NULL))
        return ;
    righttraversal(root->right, ans);
    righttraversal(root->left, ans);
    ans.push_back(root->data);
}

void leaf(node* root, vector<int> &ans){
    if(root==NULL) {
        return ; } 
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return ;
    }
    leaf(root->left, ans);
    leaf(root->right, ans);  
}


int main(){
    node* root = NULL;
    root = buildTree();
    vector<int> ans;
    ans.push_back(root->data);
    lefttraversal(root->left, ans);
    leaf(root->left, ans);
    righttraversal(root->right,ans);

    for(auto i: ans){
        cout<<i<<" ";
    }
}