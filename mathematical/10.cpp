class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ans = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> mp;
            int t = 0;
            for (int j = 0; j < points.size(); j++)
            {
                if (i != j)
                {
                    double a = points[i][0];
                    double b = points[i][1];
                    double c = points[j][0];
                    double d = points[j][1];
                    double m;
                    if (c == a)
                        m = INT_MIN;
                    else
                        m = ((d - b) * (1.0)) / (c - a);
                    mp[m]++;
                }
            }
            for (auto i : mp)
                t = max(t, i.second);
            // cout<<t+1<<" ";
            ans = max(ans, t + 1);
        }
        return ans;
    }
};