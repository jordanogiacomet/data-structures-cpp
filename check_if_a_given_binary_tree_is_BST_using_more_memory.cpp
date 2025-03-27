#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *GetNewNode(int data);
Node *Insert(Node *root, int data);
bool IsBinarySearchTree(Node *root);
bool IsSubtreeLesser(Node *root, int value);
bool IsSubtreeGreater(Node *root, int value);

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

bool IsSubtreeLesser(Node *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data <= value && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsSubtreeGreater(Node *root, int value)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data > value && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool IsBinarySearchTree(Node *root)
{
    if (root == NULL)
        return true;
    if (IsSubtreeLesser(root->left, root->data) 
       && IsSubtreeGreater(root->right, root->data) 
       && IsBinarySearchTree(root->left) 
       && IsBinarySearchTree(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}