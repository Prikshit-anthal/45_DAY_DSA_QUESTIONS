class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {

        // swap sort
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            if (nums[i] == nums[nums[i] - 1])
                i++;
            else
                swap(nums[i], nums[nums[i] - 1]);
        }

        i = 0;
        vector<int> ans;
        while (i < n)
        {
            if (i + 1 != nums[i])
                ans.push_back(nums[i]);
            i++;
        }

        return ans;
    }
};