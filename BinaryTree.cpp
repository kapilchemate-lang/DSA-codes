#include <iostream>
using namespace std;

// Structure for Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Class for Binary Tree
class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    // Function to create tree
    Node* createTree()
    {
        int value;

        cout << "Enter data (-1 for no node): ";
        cin >> value;

        if (value == -1)
            return NULL;

        Node *newNode = new Node;
        newNode->data = value;

        cout << "Enter left child of " << value << endl;
        newNode->left = createTree();

        cout << "Enter right child of " << value << endl;
        newNode->right = createTree();

        return newNode;
    }

    void create()
    {
        root = createTree();
    }

    // Inorder Traversal
    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    // Preorder Traversal
    void preorder(Node *temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    // Postorder Traversal
    void postorder(Node *temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    // Wrapper Functions
    void displayInorder()
    {
        cout << "\nInorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder()
    {
        cout << "\nPreorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder()
    {
        cout << "\nPostorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree bt;
    int choice;

    do
    {
        cout << "\n----- Binary Tree Menu -----\n";
        cout << "1. Create Tree\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                bt.create();
                break;

            case 2:
                bt.displayInorder();
                break;

            case 3:
                bt.displayPreorder();
                break;

            case 4:
                bt.displayPostorder();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
