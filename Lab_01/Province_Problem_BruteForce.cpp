#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, province=0, flag=0;
    cin >> n;

    int cities[n][n];

    int visited[n] = {0};

    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cities[i][j];
        }
    }


    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j)         ///  since a province is connected to itself... we are making it 0
            {
                cities[i][j] = 0;
            }

            else if( cities[i][j] == 1 )      /// no need to put two 1's for every connection
            {
                cities[j][i] = 0;           ///  only putting one in cities[i][j] will suffice
            }
        }
    }



    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if( cities[i][j] == 1 )       /// if we find a 1... we go to the connecting node to look for more connections
            {
                for(int k=j, p=0 ; p<n ; p++)     ///  if there's more connections then we ignore and keep iterating until we find the next 1
                {                                ///   otherwise... we found ourselves a province

                    if( cities[k][p] == 1 )      /// if the node has any connections
                    {
                        flag=1;
                        break;
                    }
                }

                if(flag == 0)       ///  since the node has no connections we increment the number of provinces
                {
                    province++;
                }

                visited[i]++;      ///  incrementing the visited nodes
                visited[j]++;
            }
        }

    }


    for(int i=0 ; i<n ; i++)
    {
        if( visited[i] == 0 )
        {
            province++;
        }
    }

    cout << "Number of Province(s): "  << province << endl;

}



//    cout << endl;
//
//    for (int i = 0 ; i < n ; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            cout << cities[i][j] << " " ;
//        }
//
//        cout << endl;
//    }

//1 0 0 1 0 0 0
//0 1 1 0 0 0 0
//0 1 1 0 0 0 0
//1 0 0 0 0 0 0
//0 0 0 0 0 0 0
//0 0 0 0 0 1 1
//0 0 0 0 0 1 1



