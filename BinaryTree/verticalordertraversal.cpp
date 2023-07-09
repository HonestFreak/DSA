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

// vertical order traversal of a binary tree
vector<int> verticalOrder(node* root) {
    map<int, map<int, vector<int>>> nodes;      // map( HD , map( level , nodes on this lvl and hd))
    queue<pair<node*, pair<int, int>>> q;
    vector<int> ans;

    // keeping nodes as map sorts itself 

    if (root == NULL) return ans;

    q.push(make_pair(root, make_pair(0, 0)));       // (root node , (hd = 0 , level = 0 ))

    while (!q.empty()) {
        pair<node*, pair<int, int>> temp = q.front();   // temp stores the last node and its hd and level
        q.pop();
        node* frontnode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontnode->data);      // stores the nodes for each specific hd and lvl

        if (frontnode->left) q.push(make_pair(frontnode->left, make_pair(hd - 1, lvl + 1)));
        if (frontnode->right) q.push(make_pair(frontnode->right, make_pair(hd + 1, lvl + 1)));
    }

    // Retrieve elements from the map in vertical order
    for (auto i : nodes) {
        for (auto j : i.second) {
            for (auto k : j.second) {
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main() {
    node* root = NULL;
    root = buildTree();
    vector<int> q = verticalOrder(root);
    for (auto i : q)
        cout << i << " ";
}
