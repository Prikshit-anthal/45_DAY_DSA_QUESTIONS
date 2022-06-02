class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int start = 0, currentBalance = 0, remainingBalance = 0;
        for (int i = 0; i < n; i++)
        {
            currentBalance += gas[i] - cost[i];

            if (currentBalance < 0)
            {
                start = i + 1;
                remainingBalance += currentBalance;
                currentBalance = 0;
            }
        }
        return remainingBalance + currentBalance >= 0 ? start : -1;
    }
};