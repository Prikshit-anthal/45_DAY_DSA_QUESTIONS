class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {

        priority_queue<pair<int, int>> p_q;
        int n = points.size();

        int max = -1e9;
        for (int i = 0; i < n; i++)
        {

            // simple remove those voilation k contion
            while (!p_q.empty() && points[i][0] - p_q.top().second > k)
                p_q.pop();

            // extract top it's best right now
            if (!p_q.empty())
            {
                auto curr = p_q.top();

                if (max < curr.first + points[i][0] + points[i][1])
                    max = curr.first + points[i][0] + points[i][1];
            }

            p_q.push({points[i][1] - points[i][0], points[i][0]});
        }

        return max;
    }
};