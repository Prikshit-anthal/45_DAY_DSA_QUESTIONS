class Solution
{
    int N, M;

public:
    int findMaxForm(vector<string> &strs, int mo, int no)
    {

        N = no; // 1's
        M = mo; // 0's

        int n = strs.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(N + 1, vector<int>(M + 1, 0)));

        return helper(n, dp, strs);
    }

    int helper(int n, vector<vector<vector<int>>> dp, vector<string> &s)
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= N; j++) // zero se start?
            {

                for (int k = 0; k <= M; k++) // zero se start?
                {
                    int x = count(s[i - 1].begin(), s[i - 1].end(), '1');
                    int y = s[i - 1].size() - x;

                    if (j >= x && k >= y)
                    {
                        // lelo nai lo

                        dp[i][j][k] = max(dp[i - 1][j - x][k - y] + 1, dp[i - 1][j][k]);
                    }
                    else
                        dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }

        return dp[n][N][M];
    }
};