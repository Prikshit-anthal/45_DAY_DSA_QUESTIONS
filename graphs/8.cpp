class Solution
{

public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Code here
        vector<int> dist[N + 1];
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
                dist[i].push_back(1e9);
        }

        int y = KnightPos[1];
        KnightPos[1] = KnightPos[0];
        KnightPos[0] = N - y + 1;

        y = TargetPos[1];
        TargetPos[1] = TargetPos[0];
        TargetPos[0] = N - y + 1;

        int x = bfs(KnightPos, TargetPos, N, dist);
        // for(int i=1;i<=N;i++)
        //{
        //     for(int j=1;j<=N;j++)
        //     cout<<dist[i][j]<<" ";
        //     cout<<endl;
        // }

        return x;
    }

    int bfs(vector<int> KnightPos, vector<int> &TargetPos, int N, vector<int> dist[])
    {
        queue<pair<int, int>> q;
        q.push({KnightPos[0], KnightPos[1]});
        dist[KnightPos[0]][KnightPos[1]] = 0;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            int arr_x[4] = {x + 2, x - 2, x + 1, x - 1};
            int arr_y[4] = {y + 1, y - 1, y + 2, y - 2};

            for (int i = 0; i < 4; i++)
            {
                int p = 0;
                if (i >= 2)
                    p = 2;
                for (int j = p; j < 2 + p; j++)
                {
                    if (checkBound(arr_x[i], arr_y[j], N))
                    {
                        // cout<<"Going "<<arr_x[i]<<" "<<arr_y[j]<<endl;
                        if (dist[x][y] + 1 < dist[arr_x[i]][arr_y[j]])
                        {
                            q.push({arr_x[i], arr_y[j]});
                            dist[arr_x[i]][arr_y[j]] = dist[x][y] + 1;
                        }
                    }
                }
            }
        }
        return dist[TargetPos[0]][TargetPos[1]];
    }

    bool checkBound(int x, int y, int N)
    {
        if (x > N || x < 1)
            return false;
        if (y > N || y < 1)
            return false;

        return true;
    }
};