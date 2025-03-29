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
bool Search(Node *root, int data);
Node *Delete(Node *root, int data);
Node *FindMin(Node *root);
void InorderTraversal(Node* root);

int main(void)
{
    Node *root;  // pointer to root node
    root = NULL; // setting tree as empty
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    root = Delete(root, 15);

    InorderTraversal(root);
    cout << '\n';
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

Node* FindMin(Node *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->left == NULL)
    {
        return root;
    }
    return FindMin(root->left);
}

Node *Delete(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children
        else
        {
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }

    return root;
}

void InorderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    InorderTraversal(root->left);
    cout << root->data << ' ';
    InorderTraversal(root->right);
}
