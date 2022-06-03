class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {

        vector<vector<int>> adj(stones.size());
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = i + 1; j < stones.size(); j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        return helper(adj);
    }

    int helper(vector<vector<int>> adj)
    {
        vector<bool> visited(adj.size(), false);
        int count = 0;

        for (int i = 0; i < adj.size(); i++)
        {
            if (visited[i] == false)
            {
                dfs(i, adj, visited);
                count++;
            }
        }
        return adj.size() - count;
    }

    void dfs(int idx, vector<vector<int>> &adj, vector<bool> &visited)
    {
        if (visited[idx])
        {
            return;
        }

        visited[idx] = true;

        for (int i = 0; i < adj[idx].size(); i++)
        {
            dfs(adj[idx][i], adj, visited);
        }
    }
};