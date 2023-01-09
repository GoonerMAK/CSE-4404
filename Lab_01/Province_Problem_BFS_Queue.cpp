#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, num;
    cin >> n;

    int visited[n] = {0};

    vector<vector<int>> cities;

    for (int i = 0 ; i < n ; i++)
    {
        vector<int> v1;             /// Vector to store column elements

        for (int j = 0; j < n; j++)
        {
            cin >> num;
            v1.push_back(num);
        }

        cities.push_back(v1);       ///  Pushing back above 1D vector to create the 2D vector
    }

    int Count = 0;   /// number of connected component count

    int city;        /// current city


    for(int i=0;i<n;i++)     /// loop through all nodes and do BFS traverse if city is not visited
    {

        if(cities[i][i] != 1)continue;     /// ignore BFS traverse if city is visited

        queue<int> Q;
        Q.push(i);

        while(!Q.empty())                   /// BFS traverse loop
        {
            city = Q.front();
            Q.pop();

            cities[city][city]=2;       /// marking current city as visited (by assigning it 2)
            visited[city]++;

                ///  go through all the neighbor of the city and push non visited
                ///  cities/nodes in to BFS queue and also mark city and neighbor as visited
            for(int j=0; j<n; j++)
            {
                if(cities[city][j]==1)
                {
                    Q.push(j);

                    cities[city][j]=2;
                    cities[j][city]=2;
                }
            }

        }

        Count++;                  /// increment connected component Count

    }

    for(int i=0 ; i<n ; i++)
    {
        cout << "Visited[i]: " << visited[i] << endl;
        if( visited[i] == 0 )
        {
            Count++;
        }
    }

    cout << "Number of Province(s): "  << Count << endl;

    return 0;
}



//1 0 0 1 0 0 0
//0 1 1 0 0 0 0
//0 1 1 0 0 0 0
//1 0 0 0 0 0 0
//0 0 0 0 0 0 0
//0 0 0 0 0 1 1
//0 0 0 0 0 1 1

