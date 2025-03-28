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
bool IsBinarySearchTree(Node* root, int data);
bool IsBstUtil(Node* root, int &previousElement);

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

bool IsBstUtil(Node* root, int &previousElement)
{
    if(root == NULL)
    {
        return true;
    }

    if(!IsBstUtil(root->left, previousElement))
    {
        return false;
    }
    
    if(root->data <= previousElement)
    {
        return false;
    }

    previousElement = root->data;

    return IsBstUtil(root->right, previousElement);
}

bool IsBinarySearchTree(Node* root)
{
    int previousElement = INT_MIN;
    return IsBstUtil(root, previousElement);
}