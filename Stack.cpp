#include <iostream>
using namespace std;

class Stack
{
private:
    int stack[10];
    int top;

public:
    // Constructor
    Stack()
    {
        top = -1;
    }

    // Push Operation
    void push()
    {
        int value;

        if(top == 9)
        {
            cout << "Stack Overflow\n";
            return;
        }

        cout << "Enter Value : ";
        cin >> value;

        top++;
        stack[top] = value;

        cout << "Element Pushed Successfully.\n";
    }

    // Pop Operation
    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Deleted Element : " << stack[top] << endl;
        top--;
    }

    // Peek Operation
    void peek()
    {
        if(top == -1)
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Top Element : " << stack[top] << endl;
    }

    // Display Operation
    void display()
    {
        if(top == -1)
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Stack Elements:\n";

        for(int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
};

int main()
{
    Stack obj;
    int choice;

    do
    {
        cout << "\n******** STACK MENU ********\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                obj.push();
                break;

            case 2:
                obj.pop();
                break;

            case 3:
                obj.peek();
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
