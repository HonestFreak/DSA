// diameter of a binary tree is the number of nodes on the longest path between 
// two leaves in the tree.

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

pair<int,int> diameter_optimized(node* root){
    if(root==NULL){
        pair<int,int> p;
        p.first = p.second = 0;
        return p;
    }
    pair<int,int> left = diameter_optimized(root->left);
    pair<int,int> right = diameter_optimized(root->right);

    // first is height and second is diameter
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(node *root){
    return diameter_optimized(root).first;
}

int main(){
    node* root = NULL;
    root = buildTree();
    cout<<"diameter is :"<<diameter(root);
}