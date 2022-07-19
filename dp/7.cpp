class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // p and c
        // TLE
        //  return factorial(m-2+n)/factorial(m-1)/factorial(n-1);

        // recursive
        //  return recur(m-1,n-1)+1;

        // dp
        vector<vector<int>> dp(n, vector<int>(m, 0));
        return paths(m, n, dp);
    }

    // recursive
    int recur(int n, int m)
    {
        if (n == 0 || m == 0)
            return 0; // ab ek he path bacha hai toh 0 dede coz yeh already added hai

        return recur(n - 1, m) + recur(n, m - 1) + 1; // new path add krlo, previous toh already added hai
    }

    // dp
    int paths(int m, int n, vector<vector<int>> dp)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + 1;
        }
        return dp[n - 1][m - 1] + 1;
    }

    // p and c
    unsigned long long factorial(unsigned long long x)
    {
        if (x == 0)
            return 1;
        return factorial(x - 1) * x;
    }
};