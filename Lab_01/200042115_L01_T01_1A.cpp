#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int party[n][n];
    int indegree[n]={0}, outdegree[n]={0};


    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> party[i][j];
        }
    }


    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int know = party[i][j];      ///  if i knows j.. then there's an outgoing edge from i to j

            outdegree[i]+= know;         ///  outdegree represents how many people a person knows

            indegree[j]+= know;         /// indegree represents how many people knows a person
        }
    }


    for(int i=0 ; i<n ; i++)
    {
        if(indegree[i] == n  &&  outdegree[i] == 1)
        {
            cout << i << " is the celeb" << endl;
            return 0;
        }
    }

    cout << "No celeb" << endl;
    return 0;

}
