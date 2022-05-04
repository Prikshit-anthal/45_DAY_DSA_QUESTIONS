class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        int behind_idx, streak = 0;
        int start_idx;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                start_idx = i + 1;
                behind_idx = i;
                break;
            }
        }

        for (int j = start_idx; j < nums.size(); j++)
        {
            if (nums[j] != 0)
            {
                nums[behind_idx] = nums[j];
                nums[j] = 0;
                if (streak == 0)
                {
                    behind_idx = j;
                }
                else
                {
                    behind_idx++;
                }
            }
            else
            {
                streak++;
            }
        }
    }
};