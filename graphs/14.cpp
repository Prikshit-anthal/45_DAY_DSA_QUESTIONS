
/// LOOKS BFS BUT DFS LOL

class Solution
{
    int count = 0;

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {

        vector<vector<int>> ad_list(n);
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
                ad_list[manager[i]].push_back(i);
        }

        for (auto i : ad_list)
        {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
        // cout<<ad_list;

        return dfs(headID, -1, ad_list, informTime);

        // return count;
    }

    //     void bfs(int idx,vector<vector<int>> & ad_list,vector<int>& informTime)
    //     {

    //         queue<int> q;
    //         q.push(idx);

    //         while(!q.empty()){

    //             int curr=q.front();
    //             q.pop();

    //             for(int i=0;i<ad_list[curr].size();i++)
    //             {
    //                 q.push(ad_list[curr][i]);
    //             }

    //             count+=informTime[curr];

    //             }
    //     }

    int dfs(int idx, int parent, vector<vector<int>> &ad_list, vector<int> &informTime)
    {
        int curr = -1;
        int max = 0;
        for (auto i : ad_list[idx])
        {
            curr = dfs(i, idx, ad_list, informTime);
            if (curr > max)
                max = curr;
        }

        if (parent != -1)
            return max + informTime[parent];
        else
            return max;
    }
};