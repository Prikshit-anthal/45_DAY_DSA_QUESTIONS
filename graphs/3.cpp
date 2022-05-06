#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        // no of components in graph
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 'd' || grid[i][j]=='0')
                    continue;
                bfs(grid, i, j);
                //cout<<i<<" "<<j<<endl;
                count++;
            }
        }
        return count;
    }

    void bfs(vector<vector<char>> &grid, int x, int y)
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = 'd';
        int c=5;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            x=curr.first;
            y=curr.second;

            // 4 childs
            int next_x, next_y;

            // 1st
            next_x = x - 1;
            next_y = y;
            if (next_x >= 0 && grid[next_x][next_y] != '0' && grid[next_x][next_y] != 'd')
                {
                    q.push({next_x, next_y});
                    grid[next_x][next_y] = 'd';
                    
                }

            // 2nd
            next_x = x + 1;
            next_y = y;
            if (next_x < grid.size() && grid[next_x][next_y] != '0' && grid[next_x][next_y] != 'd')
            {
                q.push({next_x, next_y});
                grid[next_x][next_y] = 'd';
                
            }
            // 3rd
            next_x = x;
            next_y = y - 1;
            if (next_y >= 0 && grid[next_x][next_y] != '0' && grid[next_x][next_y] != 'd')
            {
                q.push({next_x, next_y});
                grid[next_x][next_y] = 'd';
                
            }
            // 4th
            next_x = x;
            next_y = y + 1;
            if (next_y < grid[0].size() && grid[next_x][next_y] != '0' && grid[next_x][next_y] != 'd')
            {
                q.push({next_x, next_y});
                grid[next_x][next_y] = 'd';
                
            }
        }
    }
};


int main()
{
    vector<vector<char>>grid = {
        { '1', '1', '1', '1', '0' },
        { '1', '1', '0', '1', '0' },
        { '1', '1', '0', '0', '0' },
        { '0', '0', '0', '0', '0' },
    };
    Solution obj;
    cout<<endl<<obj.numIslands(grid)<<endl;

    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}