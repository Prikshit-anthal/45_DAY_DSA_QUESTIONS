class Solution
{
    int n, m;

public:
    void gameOfLife(vector<vector<int>> &board)
    {

        //-2 represents 0->1
        // 2 represents 1->0
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int curr = make_count(i, j, board);

                // live case
                if (board[i][j] == 1)
                {
                    if (curr < 2)
                        board[i][j] = 2;
                    if (curr > 3)
                        board[i][j] = 2;
                }
                if (board[i][j] == 0)
                {
                    if (curr == 3)
                        board[i][j] = -2;
                }
            }
        }

        // now real 0,1 change
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == -2)
                    board[i][j] = 1;
                if (board[i][j] == 2)
                    board[i][j] = 0;
            }
        }
    }

    int make_count(int x, int y, vector<vector<int>> &board)
    {

        int count1 = 0;

        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (i == 0 && j == 0)
                    continue;

                if (is_valid(x + i, y + j))
                {
                    if (board[x + i][y + j] > 0)
                        count1++;
                }
            }
        }

        return count1;
    }

    bool is_valid(int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;
        return true;
    }
};