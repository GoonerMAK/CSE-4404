#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool DFS(int (*arr)[100], int v, int color, int colors[], int nodes)
{
    colors[v] = color;

    cout << "Color of the nodes: ";
    for(int i=0 ; i<nodes ; i++)
    {
        cout << colors[i] << "  ";
    }
    puts("");
             
    for (int i = 0; i < nodes; i++)
    {
        if (arr[v][i] == 1)
        {
            int neighbor = i;        /// adjacent node

            if (colors[neighbor] == color)  /// adjacent nodes having same color
            {
                return false;
            }

            ///  setting up the colors as -1 and 1
            if (colors[neighbor] == 0 && !DFS(arr, neighbor, 0 - color, colors, nodes))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int nodes, edges, a, b;
    cin >> nodes >> edges;

    int adj_list[nodes][100];

    int colors[nodes] = {0};   /// initializing the colors as 0

    for (int i = 0; i < nodes ; i++)
    {
        for (int j = 0; j < nodes ; j++)
        {
            adj_list[i][j] = 0;
        }
   }

    for (int i = 0; i < edges ; i++)
    {
        cin >> a >> b;
        adj_list[a][b] = 1;        /// populating the adjacency list
        adj_list[b][a] = 1;
    }


    for (int i = 0; i < nodes ; i++)
    {
        for(int j = 0; j < nodes ; j++)
        {
            cout << adj_list[i][j] << " ";
        }
        puts("");
    }


    for (int i = 0; i < nodes; i++)
    {
        if(colors[i] == 0)  /// unexplored
        {
            if (!DFS(adj_list, i, 1, colors, nodes) )
            {
                cout << "Not Bi-Colourable" << endl;
                return 0;
            }
        }
    }

    cout << "Bi-Colourable" << endl;
    return 0;

}
