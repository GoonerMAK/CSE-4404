#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N] = {0}, f[N][N];

int sum(int x, int y) 
{
    return (a[x] + a[y]) % 100;
}

int solver(int x, int y)
{
    if (x == y) return 0;
    if (f[x][y]) return f[x][y];
    f[x][y] = 10000000;

    for (int i = x; i < y; i++)
    {
        f[x][y] = min(f[x][y], solver(i, x) + solver(i + 1, y) + sum(x, i) * sum(i + 1, y));
    }

    return f[x][y];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        memset(f, 0, sizeof f);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solver(0, n - 1) << endl;
    }

    return 0;
}
