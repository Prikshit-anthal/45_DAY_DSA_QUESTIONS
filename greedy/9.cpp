class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {

        int n = colors.length();
        int curr_count = 1;
        int curr_max = neededTime[0];
        int net_left_sum = 0;
        int net_sum = neededTime[0];

        for (int i = 1; i < n; i++)
        {
            if (colors[i] == colors[i - 1])
            {
                curr_count++;
                if (neededTime[i] > curr_max)
                    curr_max = neededTime[i];
                net_sum += neededTime[i];
                continue;
            }
            if (curr_count > 1)
            {
                // cout<<" add "<<net_sum-curr_max;
                net_left_sum += net_sum - curr_max;
                curr_count = 1;
            }
            net_sum = neededTime[i];
            curr_max = neededTime[i];
        }
        // last ke agar consecutive bachre
        if (curr_count > 1)
        {
            // cout<<" add "<<net_sum-curr_max;
            net_left_sum += net_sum - curr_max;
        }
        return net_left_sum;
    }
};