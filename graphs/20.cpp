class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int key_arr[V], parent[V];
        bool MST_added[V];

        for (int i = 0; i < V; i++)
            key_arr[i] = 1e9, MST_added[i] = false, parent[i] = -1; // child ka parent se dist

        // memset(key_arr,7,sizeof(key_arr));
        // not working uppp
        // memset(parent,-1,sizeof(parent));
        // memset(MST_added,false,sizeof(MST_added));

        // 0 node taken
        key_arr[0] = 0;

        // min pq
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{weight from parent,child}

        for (int i = 0; i < V; i++)
            pq.push({key_arr[i], i});

        int cost = 0;
        for (int i = 0; i < V; i++)
        {

            auto curr = pq.top();
            pq.pop();

            // cout<<" "<<curr.second<<endl;

            int child = curr.second;

            // yeh krna bhi zruri multiple instances bnre hai
            if (MST_added[child])
            {
                i--;
                continue;
            }
            cost += curr.first;

            MST_added[child] = true;

            for (int i = 0; i < adj[child].size(); i++)
            {
                int currr = adj[child][i][0];

                // key_arr[currr] > adj[child][i][1] zzruri to avoid multiple instances
                if (!MST_added[currr] && key_arr[currr] > adj[child][i][1])
                {
                    // cout<<" adding "<<adj[child][i][1]<<" "<<currr<<endl;
                    parent[currr] = child;
                    key_arr[currr] = adj[child][i][1];
                    pq.push({adj[child][i][1], currr});
                }
            }
        }
        return cost;
    }
};