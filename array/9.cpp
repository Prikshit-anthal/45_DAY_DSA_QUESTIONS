class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_buy_cost_till_now = prices[0];
        int max_profit_till_now = 0;
        for (int i = 1; i < prices.szie(); i++)
        {
            if (curr > min_buy_cost_till_now)
            {
                max_profit_till_now += curr - min_buy_cost_till_now;
                min_buy_cost_till_now = curr;
            }
            if (min_buy_cost_till_now > curr)
                min_buy_cost_till_now = curr;
        }
        return max_profit_till_now;
    }
};