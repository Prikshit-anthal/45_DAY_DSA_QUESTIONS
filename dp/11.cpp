class Solution
{
    int maxx = 0;
    vector<int> s1, s2;

public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        s1 = nums1;
        s2 = nums2;
        // recur(nums1.size(),nums2.size());
        // return maxx;

        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        return LC_substring(nums1.size(), nums2.size(), dp);
    }

    int recur(int n, int m)
    {
        // cout<<n<<" "<<m<<endl;
        if (n == 0 || m == 0)
            return 0;

        int curr;

        bool same = false;
        if (s1[n - 1] == s2[m - 1])
        {
            curr = recur(n - 1, m - 1) + 1;
            if (curr > maxx)
                maxx = curr;
            same = true;
        }

        recur(n - 1, m);
        recur(n, m - 1);
        return same ? curr : 0;
    }

    int LC_substring(int n, int m, vector<vector<int>> dp)
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
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
        return maxx;
    }
};