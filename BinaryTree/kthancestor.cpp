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

//kth ancestor
node* solve(node* root, int &k, int node1){
    if(root==NULL)  return NULL;
    if(root->data == node1) return root;

    node* leftans = solve(root->left, k , node1);
    node* rightans = solve(root->right,k , node1);

    if(leftans != NULL && rightans ==NULL){
        k--;
        if(k<=0){
            k = 10000;
            return root;
        }
        return leftans;
    }

    if(leftans == NULL && rightans !=NULL){
        k--;
        if(k<=0){
            k = 10000;
            return root;
        }
        return rightans;
    }

    return NULL;
}

int main(){
    node* root = NULL;
    root = buildTree();
    cout<<" k , node1";
    int k ; int node1;
    cin>>k>>node1;
    node* ans = solve(root,k,node1);
    if(ans==NULL)   cout<<-1;
    else cout<<ans->data;
}