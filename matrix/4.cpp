class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> ans;

        int n = matrix.size();
        int m = matrix[0].size();

        int innerlayers = (min(n, m) + 1) / 2;

        for (int i = 0; i < innerlayers; i++)
        {
            int down_idx, right_idx;
            // see this two idx check very imp
            //  as 1-d array or subarray jb bna vo phirse transverse na hoo

            // right
            for (int j = i; j < m - i; j++)
                ans.push_back(matrix[i][j]), right_idx = i;

            // down
            for (int j = i + 1; j < n - i; j++)
                ans.push_back(matrix[j][m - i - 1]), down_idx = m - i - 1;

            if (n - 1 - i != right_idx)
            {
                // left
                for (int j = m - i - 1 - 1; j >= i; j--)
                    ans.push_back(matrix[n - 1 - i][j]);
            }

            if (i != down_idx)
            {
                // top
                for (int j = n - i - 1 - 1; j > i; j--)
                    ans.push_back(matrix[j][i]);
            }
        }

        return ans;
    }
};