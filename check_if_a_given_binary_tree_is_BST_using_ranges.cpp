#include <iostream>
#include <limits.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *GetNewNode(int data);
Node *Insert(Node *root, int data);
bool IsBstUtil(Node *root, int minValue, int maxValue);
bool IsBinarySearchTree(Node* root);

int main(void)
{
    Node *root;  // pointer to root node
    root = NULL; // setting tree as empty

    root = Insert(root, 'F');
    root = Insert(root, 'D');
    root = Insert(root, 'J');
    root = Insert(root, 'B');
    root = Insert(root, 'E');
    root = Insert(root, 'G');
    root = Insert(root, 'K');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
    root = Insert(root, 'I');

    cout << IsBinarySearchTree(root) << '\n';
}

Node *GetNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool IsBstUtil(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;
    if ((root->data > minValue && root->data < maxValue) &&
        IsBstUtil(root->left, minValue, root->data) &&
        IsBstUtil(root->right, root->data, maxValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsBinarySearchTree(Node* root)
{
    return IsBstUtil(root, INT_MIN, INT_MAX);
}