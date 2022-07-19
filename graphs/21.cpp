
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
  