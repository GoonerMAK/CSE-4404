#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, a[N], pref[N];
long long dp[N][N];

long long sum(int x, int y) 
{
  return 1LL * pref[y] - pref[x - 1];
}

long long solve(int x, int y) 
{
  if (dp[x][y] != -1) return dp[x][y];
  if (x == y) return 0;

  dp[x][y] = 1e18;
  for (int i = x; i < y; i++) 
  {
    dp[x][y] = min(dp[x][y], solve(x, i) + solve(i + 1, y) + sum(x, i) * sum(i + 1, y));
  }

  return dp[x][y];
}

int main() 
{
  cin >> n;

  for (int i = 1; i <= n; i++) 
  {
    cin >> a[i];
    pref[i] = (pref[i - 1] + a[i]) % 100;
  }

  memset(dp, -1, sizeof dp);
  cout << solve(1, n) << endl;
  return 0;
}
