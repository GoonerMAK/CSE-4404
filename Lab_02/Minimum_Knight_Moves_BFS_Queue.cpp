#include<iostream>
#include <set>
#include <queue>
#include <climits>
using namespace std;

int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };            // all the possible movements of a knight
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

bool isValid(int x, int y, int N) 
{
    return (x >= 0 && x < N) && (y >= 0 && y < N);
}

struct Node
{
    int x, y, min_distance;
 
    Node(int x, int y, int min_distance = 0):
    x(x), y(y), min_distance(min_distance) {}
 
    bool operator<(const Node& o) const 
    {
        return x < o.x || (x == o.x && y < o.y);
    }

};


int findShortestDistance(int N, Node src, Node destination)
{
    set<Node> visited;
 
    queue<Node> q;
    q.push(src);
 
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();
 
        int x = node.x;
        int y = node.y;
        int min_distance = node.min_distance;
 
        // if the destination is reached, return distance
        if (x == destination.x  &&  y == destination.y) {
            return min_distance;
        }
 
        // if the location is not visited yet
        if (!visited.count(node))
        {
            visited.insert(node);               // mark the current node as visited

            for (int i = 0; i < 8; i++)        // check for all eight possible movements for a knight (pushing it if there's any)
            {                                 //  basically checking for unexplored nodes

                int new_x = x + row[i];       //  getting the next valid positions
                int new_y = y + col[i];
 
                if (isValid(new_x, new_y, N)) 
                {
                    q.push({new_x, new_y, min_distance + 1});
                }
            }
        }
    }
 
    return 0;

}


int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string from, to;
        cin >> from >> to;

        Node source = { (from[0]-'a'), (from[1]-'1') };

        Node destination = { (to[0]-'a'), (to[1]-'1') };

        cout << findShortestDistance(8, source, destination) << endl;
    }
    
    return 0;
}