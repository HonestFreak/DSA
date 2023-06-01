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

// lowest common ancestor
node* lca(node* root, int node1, int node2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == node1 || root->data == node2){
        return root;
    }

    node *leftans = lca(root->left, node1, node2);
    node *rightans = lca(root->right, node1, node2);

    if(leftans!=NULL && rightans != NULL)   return root;
    else if(leftans!=NULL && rightans == NULL)   return leftans;
    else if(leftans==NULL && rightans != NULL)   return rightans;
    else return NULL;
    

}

int main(){
    node* root = NULL;
    root = buildTree();
    int node1,node2;
    cout<<" node 1 , node 2"<<endl;
    cin>>node1>>node2;
    node* ans = lca(root, node1, node2);
    cout<<ans->data;
}