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

bool identicaltree(node* root1, node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1!=NULL && root2==NULL){
        return false;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }

    bool left = identicaltree(root1->left, root2->left);
    bool right = identicaltree(root1->right, root2->right);
    bool val = (root1->data == root2->data);

    if(left && right && val){
        return true;
    }
    else return false;
}

int main()
{
  node* root1 = NULL;
  node* root2 = NULL;
    root1 = buildtree();
    root2 = buildtree();
    cout<< identicaltree(root1, root2);
 return 0;
}