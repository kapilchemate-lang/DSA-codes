#include <iostream>
using namespace std;
// Node structure for Binary Search Tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize a node
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// BST class
class BST
{
private:
    Node *root;
    Node *stack[100]; // Manual stack using array
    int top;
public:
        BST() // Constructor
    {
        root = NULL;
        top = -1;
    }

    void insert(int value) // Function to insert a node into BST
    {
        Node *newNode = new Node(value);             // Step 1: Create a new node
        if (root == NULL)                                             // Step 2: Check whether the tree is empty
        {
            root = newNode;
            return;
        }
        Node *current = root;                                       // Step 3: Start traversal from root
        Node *parent = NULL;
        while (current != NULL)                                   // Step 4: Find the correct position
        {
            parent = current;
            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }
       if (value < parent->data)                                 // Step 5: Insert the new node
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    // Function to push a node into manual stack
    void push(Node *node)
    {
        if (top == 99) // Check whether stack is full
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
           top++;      // Add node to stack
        stack[top] = node;
    }

    // Function to pop a node from manual stack
    Node* pop()
    {
      if (top == -1)                          // Check whether stack is empty
            return NULL;
     Node *temp = stack[top];             // Store top node
        top--;                                                // Decrease top
        return temp;
    }

    // Function to check whether stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Non-recursive Inorder Traversal
    void inorder()
    {
        if (root == NULL)                               // Step 1: Check whether tree is empty
        {
            cout << "Tree is empty." << endl;
            return;
        }
       Node *current = root;                             // Step 2: Initialize current pointer
      top = -1;                                                   // Step 3: Reset stack
        cout << "Inorder Traversal: ";
       while (current != NULL || !isEmpty())   // Step 4: Continue until all nodes are processed
        {
          while (current != NULL)                        // Step 5: Push all left nodes
            {
                push(current);
                current = current->left;
            }
           current = pop();                                          // Step 6: Pop the top node
          cout << current->data << " ";                       // Step 7: Visit the node
          current = current->right;                               // Step 8: Move to the right subtree
        }
        cout << endl;
    }

    // Non-recursive Preorder Traversal
    void preorder()
    {
        if (root == NULL)                      // Step 1: Check whether tree is empty
        {
            cout << "Tree is empty." << endl;
            return;
        }
        top = -1;                                     // Step 2: Reset stack
        push(root);                                // Step 3: Push root node
        cout << "Preorder Traversal: ";
        while (!isEmpty())                   // Step 4: Process nodes until stack becomes empty
        {
        Node *current = pop();             // Step 5: Pop the top node
        cout << current->data << " ";   // Step 6: Visit the current node
         if (current->right != NULL)    // Step 7: Push right child first , so that left child is processed first
                push(current->right);
         if (current->left != NULL)       // Step 8: Push left child
                push(current->left);
        }
        cout << endl;
    }
};

// Main function
int main()
{
     BST tree;           // Create BST object
     int choice;
        int value;
        do
        {
            cout << "\n===== BINARY SEARCH TREE =====" << endl;
            cout << "1. Insert Node" << endl;
            cout << "2. Inorder Traversal (Non-Recursive)" << endl;
            cout << "3. Preorder Traversal (Non-Recursive)" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1: // Read value and insert into BST
                cout << "Enter value: ";
                cin >> value;
               tree.insert(value);
                cout << "Node inserted successfully." << endl;
                break;
            case 2: // Perform non-recursive Inorder traversal
                tree.inorder();
                break;
            case 3: // Perform non-recursive Preorder traversal
                tree.preorder();
                break;
            case 4: // Terminate the program
                cout << "Program terminated." << endl;
                break;
            default: // Handle invalid menu choice
                cout << "Invalid choice!" << endl;
            }
        } while (choice != 4);
    return 0;
}
