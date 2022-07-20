class Solution
{
    int n;

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        n = graph.size();
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                if (!bipartite(i, graph, visited, 1))
                    return false;
            }
        }
        return true;
    }

    bool bipartite(int node, vector<vector<int>> &adj, vector<int> &visited, int color)
    {

        if (visited[node] == color)
            return true;
        if (visited[node] == 0)
            visited[node] = color;
        if (visited[node] != color)
        {
            return false;
        }

        if (color == 1)
            color = 2;
        else
            color = 1;

        for (auto i : adj[node])
        {
            if (!bipartite(i, adj, visited, color))
                return false;
        }

        return true;
    }
};