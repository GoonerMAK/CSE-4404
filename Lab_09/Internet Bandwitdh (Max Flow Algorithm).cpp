#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 205;
const int maxnodes = 100;

int n, pr[110], cap[110][110];

// BFS algorithm to find an augmenting path from source to sink node
int bfs(int src, int des)
{
    int vis[110] = {0};
    vis[src] = 1;
    pr[src] = -1;
    queue<int> Q;
    Q.push(src);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i = 1; i <= n; i++)
        {
            if(vis[i] or cap[u][i] <= 0) continue;
            Q.push(i);
            vis[i] = 1;
            pr[i] = u;
        }
    }

    return vis[des];
}

// Find maximum flow value using the Ford-Fulkerson algorithm
int maxFlow(int src, int des)
{
    int f = 0;
    while(bfs(src, des))
    {
        int path = 1e9;
        for(int i = des; i != src; i = pr[i]) 
        {
            path = min(path, cap[pr[i]][i]);
        }

        for(int i = des; i != src; i = pr[i])
        {
            int u = pr[i];
            int v = i;
            cap[u][v] -= path;
            cap[v][u] += path;
        }

        f += path;
    }
    return f;
}

// Main function to read input and output maximum flow for each test case
int main()
{
    int test, cs = 0;
    cin >> test;
    while(test--)
    {
        // Initialize flow network
        memset(cap, 0, sizeof(cap));

        int m, s, t;
        cin >> n >> s >> t >> m;

        // Update capacity matrix for each edge
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            cap[a][b] += c;
            cap[b][a] += c;
        }

        // Print maximum flow value for the current test case
        cout << "Case " << ++cs << ": " << maxFlow(s, t) << "\n";
    }
    return 0;
}
