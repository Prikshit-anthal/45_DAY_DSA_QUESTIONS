class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();
        unsigned int max = INT_MAX;
        max++;

        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(amount + 1, max));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        unsigned int ans = unbound_knap(n, amount, coins, dp);
        if (ans == max)
            return -1;
        else
            return ans;
    }

    unsigned int unbound_knap(int n, int a, vector<int> coins, vector<vector<unsigned int>> dp)
    {

        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= a; j++)
            {
                if (j >= coins[i - 1])
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][a];
    }
};
