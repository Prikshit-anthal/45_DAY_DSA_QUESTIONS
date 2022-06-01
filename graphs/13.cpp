class Solution
{
    int n;
    vector<bool> m;
    vector<int> ans;

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        n = graph.size();

        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() == 0)
                m.push_back(true);
            else
                m.push_back(false);
        }

        vector<bool> visisted(n, false);

        for (int i = 0; i < n; i++)
        {
            if (visisted[i] == false)
                dfs_mod(i, visisted, graph);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }

    bool dfs_mod(int idx, vector<bool> &visisted, vector<vector<int>> &graph)
    {
        if (visisted[idx] == true)
        {
            if (m[idx] == true)
                return true;
            else
                return false;
        }

        visisted[idx] = true;
        bool curr = true;

        for (auto i : graph[idx])
        {
            if (!dfs_mod(i, visisted, graph))
            {
                curr = false;
                cout << "false due to " << i << " ";
            }
        }

        if (curr == true)
        {
            ans.push_back(idx);
            m[idx] = true;
        }

        return curr;
    }
};