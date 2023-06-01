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

void solve(node *root, int k , int &count, vector<int> path){
    if(root == NULL) return ;

    path.push_back(root->data);
    solve(root->left, k, count , path);
    solve(root->right, k , count ,path);

    int size= path.size();
    int sum = 0;
    for(int i= size-1; i>=0; i--){
        sum +=path[i];
        if(sum == k) {
            count++;
        }
    }
    path.pop_back();
}

int sumk(node *root, int k){
    vector<int> path;
    int count = 0;
    solve(root, k , count, path);
    return count;
}

int main(){
    node* root = NULL;
    root = buildTree();
    int k;
    cout<<"k:";
    cin>>k;
    cout<<sumk(root, k);
}