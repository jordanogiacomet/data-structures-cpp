#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data);
Node* Insert(Node *root, int data);
int FindMinIterative(Node* root);
int FindMaxIterative(Node* root);
int FindMinRecursive(Node* root);
int FindMaxRecursive(Node* root);

int main(void)
{
    Node* root; // pointer to root node
    root = NULL; // setting tree as empty
    root = Insert(root, 15);
    root = Insert(root, 16);
    root = Insert(root, 17);

    cout << "Min value iterative: " << FindMinIterative(root) << '\n';
    cout << "Max value iterative: " << FindMaxIterative(root) << '\n';
    cout << "Min value recursive: " << FindMinRecursive(root) << '\n';
    cout << "Max value recursive: " << FindMaxRecursive(root) << '\n';
}  

Node* GetNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node* Insert(Node* root, int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

int FindMinIterative(Node* root)
{   
    if(root == NULL)
    {
        cout << "Error: Tree is empty\n";\
        return -1;
    }
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int FindMaxIterative(Node* root)
{
    if(root == NULL)
    {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int FindMinRecursive(Node* root)
{
    if(root == NULL)
    {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    else if(root->left == NULL)
    {
        return root->data;
    }
    return FindMinRecursive(root->left);
}

int FindMaxRecursive(Node* root)
{
    if(root == NULL)
    {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    else if(root->right == NULL)
    {
        return root->data;
    }
    
    return FindMaxRecursive(root->right);
}