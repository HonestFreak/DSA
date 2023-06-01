#include <iostream>
#include <climits> // Added include for INT_MIN
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

// Returns sum of longest bloodline
void sumtree(node* root, int sum, int len, int& maxsum, int& maxlen) {
    if (root == NULL) {
        if (len > maxlen) {
            maxlen = len;
            maxsum = sum;
        }
        else if (len == maxlen) {
            maxsum = max(sum, maxsum);
        }
        return;
    }
    sum = sum + root->data;
    sumtree(root->left, sum, len + 1, maxsum, maxlen); // Fixed order of parameters
    sumtree(root->right, sum, len + 1, maxsum, maxlen); // Fixed order of parameters
}

int sumoflongest(node* root) {
    int len = 0;
    int maxlen = 0;
    int sum = 0;
    int maxsum = INT_MIN; // Initialize maxsum with INT_MIN

    sumtree(root, sum, 0, maxsum, maxlen); // Changed len to 0

    return maxsum;
}

int main() {
    node* root = NULL;
    root = buildTree();
    cout << sumoflongest(root);
}
