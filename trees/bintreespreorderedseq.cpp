#include <iostream>
#include <vector>
#include <queue>

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

static int idx = -1;
Node *buildTree(vector<int> preorder)
{
    idx++;
    if (preorder[idx] == -1)
        return NULL;
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// preorder traversal(root,left,right)
void preOrder(Node *root) //(1,2,3,4,5)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << endl;

    preOrder(root->left);
    preOrder(root->right);
}

// inorder traversal(left,root,right)
void inOrder(Node *root) //(2,1,4,3,5)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// postOrder traversal  (left,right,root)
void postOrder(Node *root) //(2,4,5,3,1)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// levelOrder trivarsal
void levelOrder(Node *root)
{ //(1,2,3,4,5)
    queue<Node *> q;

    q.push(root);

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

void levelOrders(Node *root)
{ // 1
  // 2,3
  // 4,5
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }
        cout << curr->data << " ";

        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

void morrisInorder(Node *root)
{

    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data;
            curr = curr->right;
        }
        else
        {
            Node *IP = curr->left;
            while (IP->right != NULL && IP->right != curr)
            {
                IP = IP->right;
            }

            if (IP->right == NULL)
            {
                IP->right = curr;
                curr = curr->left;
            }
            else
            {
                IP->right = NULL;
                cout << curr->data;
                curr = curr->right;
            }
        }
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lefHt = height(root->left);
    int rigHt = height(root->right);

    return max(lefHt, rigHt) + 1;
}

int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lefCt = count(root->left);
    int rigCt = count(root->right);

    return lefCt + rigCt + 1;
}

int sum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lefSum = sum(root->left);
    int rigSum = sum(root->right);

    return lefSum + rigSum + root->data;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);
    preOrder(root);
    inOrder(root);
    postOrder(root);
    levelOrder(root);
    levelOrders(root);
    height(root);

    return 0;
}