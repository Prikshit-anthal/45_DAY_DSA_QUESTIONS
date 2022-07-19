class Solution
{
    vector<vector<int>> matrix;

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        matrix = grid;
        int n = grid.size();
        int m = grid[0].size();

        // recur
        //  return recur(n,m);

        // dp

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));

        return min_path(n, m, dp);
    }

    // recur
    int recur(int n, int m)
    {
        if (n == 1 && m == 1)
            return matrix[0][0];

        if (n == 0 || m == 0)
            return 1e9;

        return min(recur(n - 1, m), recur(n, m - 1)) + matrix[n - 1][m - 1];
    }

    // dp
    int min_path(int n, int m, vector<vector<int>> dp)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 1 && j == 1)
                    dp[i][j] = matrix[0][0];

                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i - 1][j - 1];
            }
        }

        return dp[n][m];
    }
};