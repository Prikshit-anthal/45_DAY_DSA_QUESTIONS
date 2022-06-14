class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            auto curr = points[i];
            int calc = curr[0] * curr[0] + curr[1] * curr[1];
            pq.push({calc, i});
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++)
        {
            auto curr = pq.top();
            pq.pop();
            ans.push_back(points[curr.second]);
        }

        return ans;
    }
};