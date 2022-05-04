class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int behind_idx = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                continue;
            }
            if (behind_idx != i)
            {
                nums[behind_idx] = nums[i];
            }
            behind_idx++;
        }

        return behind_idx;
    }
};