class Solution
{
    int maxx = 0;

public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // your code here

        // recursive( S1,S2, n, m);
        // return maxx;

        // LCS se
        // base condition

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        LCS(S1, S2, n, m, dp);

        return maxx;
    }
    int recursive(string &S1, string &S2, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;

        if (S1[n - 1] == S2[m - 1])
        {
            int curr = recursive(S1, S2, n - 1, m - 1);
            if (maxx < curr + 1)
                maxx = curr + 1;
            return curr + 1;
        }

        else
        {
            int curr = max(recursive(S1, S2, n, m - 1), recursive(S1, S2, n - 1, m)); // fake calls just for maxx
            if (maxx < curr)
                maxx = curr;
            return 0;
        }
    }

    int LCS(string &S1, string &S2, int n, int m, vector<vector<int>> &dp)
    {

        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > maxx)
                        maxx = dp[i][j];
                }
                else
                {
                    // nothing needed necessarily
                    dp[i][j] = 0; /// can give zero at initialisation too
                }
            }
        }
    }
};