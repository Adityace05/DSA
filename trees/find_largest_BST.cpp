#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Info
{
public:
    int mx;
    int mn;
    int sz;

    Info(int mx, int mn, int sz)
    {
        this->mx = mx;
        this->mn = mn;
        this->sz = sz;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

Node *buildBST(vector<int> &arr)
{
    Node *root = NULL;

    for (int val : arr)
        root = insert(root, val);

    return root;
}

Info helper(Node *root)
{
    // Empty tree is a BST
    if (root == NULL)
        return Info(INT_MIN, INT_MAX, 0);

    Info left = helper(root->left);
    Info right = helper(root->right);

    // Current subtree is a BST
    if (left.mx < root->data && root->data < right.mn)
    {
        return Info(
            max(root->data, right.mx), // maximum value
            min(root->data, left.mn),  // minimum value
            left.sz + right.sz + 1     // size
        );
    }

    // Not a BST
    return Info(INT_MAX, INT_MIN, max(left.sz, right.sz));
}

int largestBST(Node *root)
{
    return helper(root).sz;
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node *root = buildBST(arr);

    cout << "Largest BST size = " << largestBST(root) << endl;

    return 0;
}