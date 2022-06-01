class Solution
{
    vector<vector<int>> ans;
    int n;

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        n = candidates.size();

        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        for (int i = 0; i < n; i++)
        {

            /// avoiding case 111111111 type see first 1 has taken all cases of other one's
            // too soo avoiding other one's too redo same task
            if (i > 0 && candidates[i] == candidates[i - 1])
                continue;

            backTrack(i, candidates, target, temp);
        }

        return ans;
    }

    void backTrack(int start_idx, vector<int> &candidates, int target, vector<int> temp)
    {
        int new_target;
        if (candidates[start_idx] > target)
        {
            return;
        }

        temp.push_back(candidates[start_idx]);

        new_target = target - candidates[start_idx];

        if (new_target == 0)
        {

            if (!isSame(temp))
                ans.push_back(temp);

            return;
        }

        for (int i = start_idx + 1; i < n; i++)
        {

            /// avoiding case 111111111 type see first 1 has taken all cases of other one's
            // too soo avoiding other one's too redo same task
            if (i > start_idx + 1 && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] <= new_target)
                backTrack(i, candidates, new_target, temp);
        }
    }

    bool isSame(vector<int> &temp)
    {
        for (auto i : ans)
        {

            if (i == temp)
                return true;
        }

        return false;
    }
};