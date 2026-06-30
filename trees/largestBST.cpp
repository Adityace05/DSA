#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int INT_MIN = -1000000;
int INT_MAX = 1000000;
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

    Info(int max, int min, int size)
    {
        mx = max;
        mn = min;
        sz = size;
    }
};
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}
Node *buildBST(vector<int> &arr)
{
    Node *root = NULL;

    for (int val : arr)
    {
        root = insert(root, val);
    }
}

Info helper(Node *root)
{
    if (root == NULL)
    {
        return Info(INT_MIN, INT_MAX, 0);
    }
    Info left = helper(root->left);
    Info right = helper(root->right);

    if (left.mx < root->data && root->data < right.mn)
    {
        return Info(min(left.mx, root->data), max(right.mx, root->data), left.sz + right.sz + 1);
    }
    return Info(INT_MAX, INT_MIN, max(left.sz, right.sz));
}

int largestBst(Node *root)
{
    Info info = helper(root);
    return info.sz;
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(arr);

    return 0;
}