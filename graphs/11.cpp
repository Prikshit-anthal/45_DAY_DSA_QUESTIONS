#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int count_extra = 0;
    int components = 0;

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                components++;
                modified_dfs(i, -1, adj, visited, n);
            }
        }
        cout<<" components "<<components-1<<" count "<<count_extra/2<<endl;
        if (components-1 > count_extra / 2)
        {
            return -1;
        }
        else
        {
            return min(components-1, count_extra / 2);
        }
    }

    void modified_dfs(int v, int p, vector<vector<int>> &graph, vector<bool> &visited, int n)
    {
        visited[v] = true;

        for (int i = 0; i < graph[v].size(); i++)
        {
            if (visited[graph[v][i]] && graph[v][i] != p)
            {
                count_extra++;
            }
            else if (graph[v][i] == p)
            continue;
                else modified_dfs(graph[v][i], v, graph, visited, n);
        }
    }
};

int main()
{
   Solution obj;
   vector<vector<int>> v =
       {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};

   cout << obj.makeConnected(6, v);

   return 0;
}