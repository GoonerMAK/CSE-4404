#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 16;
const int INF = 1000000000;

int n;
int priority[MAX][MAX];
int memo[1 << MAX];

int solve(int mask)
{
    if (memo[mask] != 0) 
    {
        return memo[mask];
    }

    if (mask == (1 << n) - 1)   /*  if mask has all 1's in it  */
    {
        return 0;
    }

    int result = 0;
    int max_priority = 0;
    for (int i = 0; i < n; i++) 
    {
        if (!(mask & (1 << i)))       /* if the man's not married yet */
        {
            for (int j = 0; j < n; j++) 
            {
                if (!(mask & (1 << j)))    /* if the woman's not married yet */
                {
                    max_priority = max(max_priority, priority[i][j] + solve(mask | (1 << i)));
                }
            }

            //result =  max(result, (solve(mask | (1 << i)) + max_priority));
            
        }
    }

    return max_priority;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> priority[i][j];
        }
    }

    memset(memo, 0, sizeof(memo));
    int max_priority = solve(0);

    cout << max_priority << endl;

    return 0;
}
