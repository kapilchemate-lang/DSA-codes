#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insert(Node *root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }

    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void levelOrder(Node *root)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left != NULL)
            q.push(temp->left);

        if(temp->right != NULL)
            q.push(temp->right);
    }
}

Node* copyTree(Node *root)
{
    if(root == NULL)
        return NULL;

    Node *newNode = createNode(root->data);

    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

int height(Node *root)
{
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

void leafNodes(Node *root)
{
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    leafNodes(root->left);
    leafNodes(root->right);
}

int main()
{
    Node *root = NULL;
    Node *newRoot = NULL;

    int n, value;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Original BST: ";
    levelOrder(root);

    newRoot = copyTree(root);

    cout << "\nCopied BST: ";
    levelOrder(newRoot);

    cout << "\nHeight of tree: " << height(root);

    cout << "\nLeaf nodes: ";
    leafNodes(root);

    return 0;
}
