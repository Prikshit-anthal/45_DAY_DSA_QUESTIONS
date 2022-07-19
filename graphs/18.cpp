class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
            dp[i][i] = 0;

        for (int i = 0; i < edges.size(); i++)
        {
            auto curr = edges[i];
            dp[curr[0]][curr[1]] = curr[2];
            dp[curr[1]][curr[0]] = curr[2];
        }

        // ...imp outer loop k kaa always
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < n; i++)
                {

                    if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) // see 1e9 wala imp
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int minn = INT_MAX;
        int min_idx = -1;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] <= distanceThreshold && i != j)
                    count++;
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
            if (count <= minn)
            {
                // cout<<i<<" ";
                minn = count;
                min_idx = i;
            }
        }

        return min_idx;
    }
};