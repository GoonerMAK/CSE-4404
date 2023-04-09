import java.util.*;

public class Mixtures
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();      // the number of mixtures
        int[] a = new int[n];

        int[][] dp = new int[n][n];
        int[][] colors = new int[n][n];

        for (int i = 0; i < n; i++)
        {
            a[i] = sc.nextInt();
            dp[i][i] = 0;                    // if mixed with itself
            colors[i][i] = a[i];            // if mixed with itself
        }

        // Iterating over all possible lengths of the sub-array
        for (int len = 2 ; len <= n ; len++)                      // the smallest sub-array size needed: 2
        {
            for (int i = 0; i <= n-len ; i++)   // Iterating over all possible starting indices of the sub-array
            {
                int j = i + len - 1;        // Computing the ending index of the sub-array

                dp[i][j] = 100000000;     // alternative: dp[i][j] = Integer.MAX_VALUE;

                for (int k = i ; k < j ; k++)
                {
                    // Computing the amount of smoke produced when mixing mixtures i through k and mixtures k+1 through j
                    int mix = dp[i][k] + dp[k+1][j] + colors[i][k]*colors[k+1][j];

                    if (mix < dp[i][j])
                    {
                        dp[i][j] = mix;
                        colors[i][j] = (colors[i][k] + colors[k+1][j]) % 100;
                    }
                }

            }
        }

        System.out.println(dp[0][n-1]);

        sc.close();
    }
}
