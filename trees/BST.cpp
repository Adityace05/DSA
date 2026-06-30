#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

bool searchBST(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (key > root->data)
    {
        return searchBST(root->right, key);
    }
    else
    {
        return searchBST(root->left, key);
    }
}
Node *getIS(Node *root)
{ // left most node in right subtree
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *delNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key < root->data)
    {
        root->left = delNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *IS = getIS(root->right);
            root->data = IS->data;
            root->right = delNode(root->right, IS->data);
        }
    }
    return root;
}
int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(arr);
    int key = 1;
    cout << searchBST(root, key);
    delNode(root, 6);

    return 0;
}