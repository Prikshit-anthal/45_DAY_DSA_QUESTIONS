class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        stack<int> s; // monotonic decreasing stack
        int n = temperatures.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            while (!s.empty())
            {
                if (temperatures[s.top()] < temperatures[i])
                {
                    ans[s.top()] = i - s.top();
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            s.push(i);
        }

        return ans;
    }
};