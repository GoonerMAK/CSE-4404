#include<bits/stdc++.h>
using namespace std;

void DFS( vector<vector<int>> &cities, int i, int j )
{
    cities[i][j] = 0;

    for(int k=0 ; k<cities.size() ; k++)
    {
        if(cities[j][k] == 1 )
        {
            DFS(cities, j, k);   ///  every time we encounter 1, the function will next
        }                       ///   traverse the j'th row (looking for connecting nodes)
    }
}


int main()
{
    int n, provinces=0, num;
    cin >> n;

    vector<vector<int>> cities;

    for (int i = 0 ; i < n ; i++)   /// inputing into the vector of vectors
    {
        vector<int> v1;

        for (int j = 0; j < n; j++)
        {
            cin >> num;
            v1.push_back(num);
        }
        cities.push_back(v1);
    }


    for (int i = 0 ; i < cities.size() ; i++)
    {
        for (int j = 0; j < cities[0].size() ; j++)
        {
            if( cities[i][j] == 1 )   /// every time we encounter a 1... we traverse the j'th row
            {
                provinces++;             ///  let's say... we encountered 1 on cities[1][3]... then
                DFS(cities, i, j);      ///   we DFS() will traverse the 3rd row to find the next unexplored node
            }
        }
    }

    cout << "Number of Province(s): "  << provinces << endl;
}


//1 0 0 1 0 0 0
//0 1 1 0 0 0 0
//0 1 1 0 0 0 0
//1 0 0 1 0 0 0
//0 0 0 0 1 0 0
//0 0 0 0 0 1 1
//0 0 0 0 0 1 1

// 1,4  2,3  5  6,7

//    cout <<endl;
//    for (int i = 0; i < cities.size(); i++)
//    {
//        for (int j = 0; j < cities[i].size(); j++)
//        {
//            cout << cities[i][j] << " ";
//        }
//        cout << endl;
//    }


