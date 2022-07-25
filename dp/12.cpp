class Solution
{
    vector<int> arr;

public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> arr;
        int n = nums.size();

        map<int, bool> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]] = true;

        for (auto i : mp)
            arr.push_back(i.first);

        // now LCS
        int m = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        return LCS(nums, arr, n, m, dp);
    }

    int LCS(vector<int> nums, vector<int> arr, int n, int m, vector<vector<int>> dp)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums[i - 1] == arr[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
};