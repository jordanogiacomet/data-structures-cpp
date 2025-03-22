#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data);
Node* Insert(Node *root, int data);
int FindHeight(Node* root);

int main(void)
{
    Node* root; // pointer to root node
    root = NULL; // setting tree as empty
    root = Insert(root, 15);
    root = Insert(root, 16);
    root = Insert(root, 17);

    cout << "The height of tree is: " << FindHeight(root) << '\n';
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

int FindHeight(Node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

