#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node *GetNewNode(char data);
Node *Insert(Node *root, char data);
void PreorderTraversal(Node *root);
void InorderTraversal(Node *root);
void PostorderTraversal(Node *root);

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

    PreorderTraversal(root);
    cout << '\n';

    InorderTraversal(root);
    cout << '\n';

    PostorderTraversal(root);
    cout << '\n';
}

Node *GetNewNode(char data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node *Insert(Node *root, char data)
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

void PreorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << ' ';
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void InorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    InorderTraversal(root->left);
    cout << root->data << ' ';
    InorderTraversal(root->right);
}

void PostorderTraversal(Node *root)
{
    if (root == NULL) return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << ' ';
}