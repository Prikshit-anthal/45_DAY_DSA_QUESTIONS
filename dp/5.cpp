class Solution
{
    int m = 1e9 + 7;
    vector<vector<int>> movements = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {0, 1, 7}, {6, 2}, {1, 3}, {2, 4}};

public:
    int knightDialer(int n)
    {
        //         int count=0;

        //         for(int i=0;i<10;i++)
        //         {

        //            count += recursive(i,n-1)%m;
        //             count=count%m;
        //         }

        //         return count;

        // dp
        vector<vector<int>> dp(n + 1, vector<int>(10, -1));

        for (int i = 0; i < 10; i++)
            dp[0][i] = 1;

        return dp_fun(n, 10, dp);
    }

    //     int recursive(int x,int n)
    //     {
    //         // cout<<x<<" ";
    //         if(n==0) {return 1;}

    //         int count=0;

    //         for(int i=0;i<movements[x].size();i++)
    //         count+=recursive(movements[x][i],n-1);

    //         return count;
    //     }

    int dp_fun(int n, int pos, vector<vector<int>> dp)
    {

        for (int i = 1; i <= n; i++)
        {

            for (int j = 0; j < pos; j++)
            {
                int count = 0;
                for (int x = 0; x < movements[j].size(); x++)
                    count = (count % m + dp[i - 1][movements[j][x]] % m) % m;

                dp[i][j] = count;
            }
        }

        ////seeee n-1 pe ans;
        int ans = 0;
        for (int i = 0; i < pos; i++)
            ans += dp[n - 1][i], ans %= m;
        return ans;
    }
};