class Solution
{
    vector<int> v;
    vector<vector<int>> ans;
    int n, k;

public:
    vector<vector<int>> combine(int n, int k)
    {

        this->n = n;
        this->k = k;

        for (int i = 0; i < n; i++)
            v.push_back(i + 1);

        vector<int> temp;
        backTrack(0, k + 1, temp);

        return ans;
    }

    void backTrack(int start_idx, int no_of, vector<int> temp)
    {
        int new_of = no_of - 1;

        if (no_of > n - start_idx + 1)
        {
            return;
        }

        if (start_idx != 0)
            temp.push_back(start_idx);

        if (new_of == 0)
        {
            ans.push_back(temp);
            return; // ans
        }

        for (int i = start_idx + 1; i <= n; i++)
        {
            backTrack(i, new_of, temp);
        }
    }
};