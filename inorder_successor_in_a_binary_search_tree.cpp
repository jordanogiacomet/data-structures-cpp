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
Node *GetSuccessor(Node *root, int data);
Node *Find(Node *root, int data);
Node *FindMin(Node *root);

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

    if(GetSuccessor(root, 8) != NULL)
    {
        cout << GetSuccessor(root, 8)->data << '\n';
    }
    else 
    {
        cout << "The node has no successor!\n";
    }
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

Node *Find(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data == root->data)
        return root;
    else if (data <= root->data)
        return Find(root->left, data);
    else
        return Find(root->right, data);
}

Node *FindMin(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left == NULL)
    {
        return root;
    }
    return FindMin(root->left);
}

Node *GetSuccessor(Node *root, int data)
{   
    // Search the node - O(h)
    Node *current = Find(root, data);
    if (current == NULL)
        return NULL;
    // Case 1: Node has right subtree
    if(current->right != NULL) 
    {
        return FindMin(current->right);
    }
    // Case 2: No right subtree
    else 
    {   
        Node* successor = NULL;
        Node* temp = root;
        while(temp != NULL)
        {
            if(temp->data > current->data)
            {
                successor = temp;
                temp = temp->left;
            }
            else 
            {
                temp = temp->right;
            }
        }
        return successor;
    }
}
