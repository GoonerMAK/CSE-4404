#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool flag = true;

void bfs(int u, int color[], int nodes, vector<vector<int>> g)
{
    queue<int> q;       // queue will store the nodes to be processed

    q.push(u);              // Adding the first node to the queue and color it with color 0.
    color[u] = 0;

    while (!q.empty())          // traversing the graph
    {
        int temp = q.front();   // Getting the first node from the queue and remove it
        q.pop();

        for (int i = 0; i < g[temp].size(); i++)     // Traversing all the neighbors of the current node
        {
            int v = g[temp][i];

            // If the neighbor has not been colored yet, color it with the opposite color of the current node
            if (color[v] == -1)
            {
                color[v] = 1 - color[temp];
                q.push(v);
            }

            // If the neighbor has already been colored with the same color as the current node,
            // the graph cannot be bicolorable, so set the flag to false and return from the function.
            else if (color[v] == color[temp])
            {
                flag = false;
                return;
            }

        }

    }
}

int main()
{
    int nodes, edges, a, b;
    cin >> nodes >> edges;

    int color[nodes];    // Create an array to store the color of each node.

    vector<vector<int>> g(nodes);    // Create an adjacency list to store the graph.

    // Read in the edges of the graph and add them to the adjacency list.
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    fill(color, color + nodes, -1);

    for (int i = 0; i < nodes; i++)     // Traverse the graph and color the nodes
    {
        if (color[i] == -1)
        {
            bfs(i, color, nodes, g);
        }
    }

    if (flag)
    {
        cout << "BICOLORABLE" << endl;
    }
    else
    {
        cout << "NOT BICOLORABLE" << endl;
    }

    return 0;
}
