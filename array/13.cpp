class Solution
{
    vector<vector<int>> ans;

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int target = -nums[i];

            if (i == 0 || nums[i] != nums[i - 1])
                twoSum(i + 1, n, nums, target);
        }

        return ans;
    }

    void twoSum(int idx, int n, vector<int> &nums, int target)
    {

        unordered_map<int, int> m;
        for (int i = idx; i < n; i++)
        {

            if (m.find(target - nums[i]) != m.end())
            {
                int p = ans.size();

                int x = nums[idx - 1];
                int y = target - nums[i];
                int z = nums[i];

                if (p > 0 && (ans[p - 1][0] == x && ans[p - 1][1] == y && ans[p - 1][2] == z))
                    continue;
                ans.push_back({nums[idx - 1], target - nums[i], nums[i]});
            }

            m[nums[i]] = i;
        }
    }
};