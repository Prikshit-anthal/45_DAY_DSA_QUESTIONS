class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int z = 0, o = 0, t = 0;
        for (auto itr : nums)
        {
            if (itr == 0)
                z++;
            else if (itr == 1)
                o++;
            else
                t++;
        }
        int k = 0;
        for (int i = 0; i < 3; i++)
        {
            int num = i == 0 ? z : (i == 1) ? o
                                            : t;
            int j;
            for (j = k; j < num + k; j++)
            {
                nums[j] = i;
            }
            k = j;
        }
    }
};