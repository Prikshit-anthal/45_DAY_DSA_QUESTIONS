#include <bits/stdc++.h>
using namespace std;

// idea keep track of min value always in behind (curr idx)
//  if curr-behind > curr_max //new max has come

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_buy_cost_till_now = prices[0];
        int max_profit_till_now = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int curr = prices[i];
            if (curr - min_buy_cost_till_now > max_profit_till_now)
            {
                max_profit_till_now = curr - min_buy_cost_till_now;
            }
            if (curr < min_buy_cost_till_now)
            {
                min_buy_cost_till_now = curr;
            }
        }
        return max_profit_till_now;
    }
};

int main()
{
    Solution obj;
    vector<int> v =
        {2, 1, 2, 1, 0, 0, 1};
    cout << obj.maxProfit(v);

    return 0;
}
