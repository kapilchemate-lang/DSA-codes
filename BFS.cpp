#include <iostream>
using namespace std;

int graph[10][10];
int visited[10];
int n;

// Create Graph
void createGraph()
{
    int edges, u, v;

    cout << "Enter number of vertices: ";
    cin >> n;

    // Initialize matrix with 0
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";

    for(int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    cout << "Graph created successfully.\n";
}

// Display Adjacency Matrix
void display()
{
    cout << "\nAdjacency Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }
}

// DFS
void DFS(int vertex)
{
    cout << vertex + 1 << " ";

    visited[vertex] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int choice, start;

    do
    {
        cout << "\n----- GRAPH MENU -----\n";
        cout << "1. Create Graph\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. DFS Traversal\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                createGraph();
                break;

            case 2:
                display();
                break;

            case 3:

                // Reset visited array
                for(int i = 0; i < n; i++)
                {
                    visited[i] = 0;
                }

                cout << "Enter starting vertex: ";
                cin >> start;

                cout << "DFS Traversal: ";

                DFS(start - 1);

                cout << endl;
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 4);

    return 0;
}
