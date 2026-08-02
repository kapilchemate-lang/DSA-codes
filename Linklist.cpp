#include <iostream>
using namespace std;

// Structure
struct Node
{
    int data;
    Node *next;
};

// Class
class LinkedList
{
private:
    Node *head;

public:

    // Constructor
    LinkedList()
    {
        head = NULL;
    }

    // Create Linked List
    void create()
    {
        int n;

        cout << "Enter number of nodes : ";
        cin >> n;

        for(int i = 1; i <= n; i++)
        {
            Node *newNode = new Node;

            cout << "Enter data : ";
            cin >> newNode->data;

            newNode->next = NULL;

            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                Node *temp = head;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newNode;
            }
        }
    }

    // Insert at End
    void insert()
    {
        Node *newNode = new Node;

        cout << "Enter data : ";
        cin >> newNode->data;

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "Node Inserted Successfully.\n";
    }

    // Delete from End
    void deleteNode()
    {
        if(head == NULL)
        {
            cout << "Linked List is Empty.\n";
            return;
        }

        if(head->next == NULL)
        {
            delete head;
            head = NULL;
            cout << "Node Deleted Successfully.\n";
            return;
        }

        Node *temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        cout << "Node Deleted Successfully.\n";
    }

    // Display
    void display()
    {
        if(head == NULL)
        {
            cout << "Linked List is Empty.\n";
            return;
        }

        Node *temp = head;

        cout << "Linked List : ";

        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

// Main Function
int main()
{
    LinkedList obj;
    int choice;

    do
    {
        cout << "\n******** MENU ********\n";
        cout << "1. Create\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                obj.create();
                break;

            case 2:
                obj.insert();
                break;

            case 3:
                obj.deleteNode();
                break;

            case 4:
                obj.display();
                break;

            case 5:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice.\n";
        }

    } while(choice != 5);

    return 0;
}
