#include <iostream>
#include <vector>
#include <string>
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
        right = left = NULL;
    }
};
int idx = -1;
Node *buildTree(vector<int> &preorder)
{
    idx++;
    if (preorder[idx] == -1)
        return NULL;
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}
Node *rightMostinLeftSubtree(Node *root)
{
    while (root != NULL)
    {
        root = root->right;
    }
    return root;
}
Node *leftMostinLRightSubtree(Node *root)
{
    while (root != NULL)
    {
        root = root->right;
    }
    return root;
}

vector<int> getPreSuc(Node *root, int key)
{
    Node *curr = root;
    Node *pred = NULL;
    Node *succ = NULL;

    while (curr != NULL)
    {
        if (key < curr->data)
        {
            succ = curr;
            curr = curr->left;
        }
        if (key > curr->data)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            if (curr->left != NULL)
            {
                pred = rightMostinLeftSubtree(curr->left);
            }
            if (curr->right != NULL)
            {
                succ = leftMostinLRightSubtree(curr->right);
            }
            break;
        }
    }
    return {pred->data, succ->data};
}
int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);
    int key = 4;
    getPreSuc(root, key);

    return 0;
}