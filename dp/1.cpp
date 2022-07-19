class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(n+1,0); //i d dp
        
        //base condition
        dp[0]=1;
        
        return helper(n,dp);
    }
    
    int helper(int n,vector<int> & dp)
    {
        for(int i=1;i<=n;i++)
        {
            if(i>=2)
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
            else
                dp[i]=dp[i-1];
        }
        return dp[n];
    }
};