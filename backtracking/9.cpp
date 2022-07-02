class Solution
{
    int n;
    vector<vector<int>> ans;

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        n = nums.size();
        helper(nums, 0);

        return ans;
    }

    void helper(vector<int> &nums, int idx, vector<int> temp = {})
    {

        // getting empty case
        if (idx == n && temp.size() == 0)
            ans.push_back(temp);

        // base condn
        if (idx == n)
            return;

        // condition diagram

        // nai uthaya
        helper(nums, idx + 1, temp);

        // uthaya
        temp.push_back(nums[idx]);
        ans.push_back(temp);
        helper(nums, idx + 1, temp);
    }
};