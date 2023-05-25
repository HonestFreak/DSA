#include<iostream>
#include<queue>
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
    if(d == -1) return NULL;
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}


// level order traversal
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* f = q.front();
        cout<< f->data << " ";
        q.pop();
        if(f->left) q.push(f->left);
        if(f->right)q.push(f->right);
    }
}    

//inorder traversal
void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}

//preorder traversal
void preorder(node* root){
    if(root == NULL) return;
    cout<< root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

//postorder traversal
void postorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    inorder(root->right);
    cout<< root->data << " ";
}

int main(){
    node* root = NULL;
    root = buildTree();
    cout<<"lever oder:";
    levelOrderTraversal(root);
    cout<<endl<<"inorder:";
    inorder(root);
    cout<<endl<<"preorder:";
    preorder(root);
    cout<<endl<<"postorder:";
    postorder(root);
 return 0;
}