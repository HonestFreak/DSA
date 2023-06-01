#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <vector>

using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree() {
    int d;
    cin >> d;

    if (d == -1) {
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

// bottom view of a binary tree
vector<int> bottomview(node* root) {
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> topNode;   // singular mapping , each hd will have just one value i.e. bottom node data
    // map< top node , hd >
    queue<pair<node* , int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node* , int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd= temp.second;
        
      
        topNode[hd] = frontNode->data; 

        // to traverse
        if(frontNode->left) q.push(make_pair(frontNode->left, hd-1));       
        if(frontNode->right) q.push(make_pair(frontNode->right, hd+1));
    }

    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}

int main() {
    node* root = NULL;
    root = buildTree();
    vector<int> q = bottomview(root);
    for (auto i : q)
        cout << i << " ";
}
