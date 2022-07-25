class Solution
{
    int m, n;

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {

        m = matrix.size();
        n = matrix[0].size();

        pair<int, int> p = {-1, -1};

        int ans = 0;

        // for(int i=m;i>0;i--)
        // {
        //     for(int j=n;j>0;j--)
        //     {
        //         ans=max(recur({i,j},p,matrix),ans);
        //     }
        // }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = m; i > 0; i--)
        {
            for (int j = n; j > 0; j--)
            {
                ans = max(memo({i, j}, p, matrix, dp), ans);
            }
        }
        return ans;
    }

    int recur(pair<int, int> c, pair<int, int> p, vector<vector<int>> &matrix)
    {

        int i = c.first;
        int j = c.second;

        // cout<<i<<" "<<j<<endl;

        if (p.first != -1)
        {

            if (i <= 0 || i > m || j <= 0 || j > n || matrix[i - 1][j - 1] <= matrix[p.first - 1][p.second - 1])
            {

                // cout<<i<<m<<j<<n<<" ret 0 "<<endl;
                return 0;
            }
        }

        // dfs
        int curr = 0;
        pair<int, int> arr[] = {{i - 1, j}, {i, j - 1}, {i + 1, j}, {i, j + 1}};
        for (int i = 0; i < 4; i++)
        {
            if (arr[i] == p)
                continue;

            curr = max(recur(arr[i], c, matrix), curr);
        }
        return curr + 1;
    }

    int memo(pair<int, int> c, pair<int, int> p, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        int i = c.first;
        int j = c.second;

        // cout<<i<<" "<<j<<endl;

        if (p.first != -1)
        {

            if (i <= 0 || i > m || j <= 0 || j > n || matrix[i - 1][j - 1] <= matrix[p.first - 1][p.second - 1])
            {

                // cout<<i<<m<<j<<n<<" ret 0 "<<endl;
                return 0;
            }
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // dfs
        int curr = 0;
        pair<int, int> arr[] = {{i - 1, j}, {i, j - 1}, {i + 1, j}, {i, j + 1}};
        for (int i = 0; i < 4; i++)
        {
            if (arr[i] == p)
                continue;

            curr = max(memo(arr[i], c, matrix, dp), curr);
        }
        return dp[i][j] = curr + 1;
    }
};