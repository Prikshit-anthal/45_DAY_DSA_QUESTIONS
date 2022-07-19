class Solution
{
public:
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        // Code here

        vector<vector<int>> adj(N);

        for (auto i : prerequisites)
        {
            adj[i.first].push_back(i.second);
        }

        // DFS

        // bool already_visited[N]={false},visited[N]={false};

        // for(int i=0;i<N;i++)
        // {
        //     if(already_visited[i]) continue;
        //    // cout<<i<<" s ";
        //     if(dfs_cycle_check(adj,already_visited,visited,i))
        //     return false;

        //    // cout<<" hui ";

        // }
        // return true;

        // TOPO
        int indegree[N] = {0};
        for (auto i : prerequisites)
        {
            indegree[i.second]++;
        }

        queue<int> zero_indegrees, topo;
        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
                zero_indegrees.push(i);
        }

        // bfs khans
        while (!zero_indegrees.empty())
        {
            auto curr = zero_indegrees.front();
            zero_indegrees.pop();

            for (auto i : adj[curr])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    zero_indegrees.push(i);
            }

            topo.push(curr);
        }

        // cout<<topo.size()<<" "<<N;
        if (topo.size() == N)
            return true;
        else
            return false;
    }

    // TLE

    // 	bool dfs_cycle_check(vector<vector<int>> list, bool already_visited[], bool visited[], int i)
    // {
    //     // cout<<i<<" ";
    //     if (already_visited[i] == true)
    //         return false;

    //     if (visited[i] == true)
    //     { // cout<<i<<"true"<<" ";
    //         return true;
    //     }
    //     visited[i] = true;
    //     bool res=false;
    //     for (int j = 0; j < list[i].size(); j++)
    //     {
    //         // cout<<"enter "<<endl;
    //          res = dfs_cycle_check(list, already_visited, visited, list[i][j]);
    //          if(res) break;
    //     }

    //     already_visited[i] = true;
    //     visited[i] = false;
    //     return res;
    // }
};