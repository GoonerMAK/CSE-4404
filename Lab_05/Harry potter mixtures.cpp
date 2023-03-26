#include<bits/stdc++.h>
using namespace std;

const int N=105;
int n,m,a[N];
int f[N][N];
int prefix_sum[N];

int solver(int x,int y)
{
    if(x==y) return 0;
    if(f[x][y]) return f[x][y];
    int ans=10000000;

    for(int i=x ; i<y ; i++)
    {
        ans=min(ans,solver(x,i)+solver(i+1,y)+(prefix_sum[i]-prefix_sum[x-1]+100)*(prefix_sum[y]-prefix_sum[i]));
    }
    return f[x][y]=ans;
}

int main()
{
    cin>>n;
    while(n--)
    {
        memset(f,0,sizeof(f));
        memset(prefix_sum,0,sizeof(prefix_sum));

        cin>>m;

        for(int i=0 ; i<m ; i++)
        {
            cin >> a[i];
        }

        for(int i=1 ; i<=m ; i++)
        {
            prefix_sum[i-1] = (a[i] + a[i-1]) % 100;

            cout << prefix_sum[i-1] << " ";
        }
        puts("");

        cout<<solver(0, m-1)<<endl;
    }
    return 0;
}
