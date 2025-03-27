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
void LevelOrder(Node *root);

int main(void)
{
    Node *root;  // pointer to root node
    root = NULL; // setting tree as empty
    root = Insert(root, 'C');
    root = Insert(root, 'B');
    root = Insert(root, 'Z');
    root = Insert(root, 'A');
    root = Insert(root, 'D');

    LevelOrder(root);
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

void LevelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    // while there is at least one discovered node
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop(); // removing element at front
    }
}