class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {

        int sum = 0, n = nums.size();
        int temp = n * (n + 1) / 2;

        for (auto itr : nums)
        {
            sum += itr;
        }

        return temp - sum;
    }
};