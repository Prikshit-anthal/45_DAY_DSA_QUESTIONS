class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {

        if (nums.size() == 3)
        {
            return nums[0] * nums[1] * nums[2];
        }
        sort(nums.begin(), nums.end());
        for (auto i : nums)
            cout << i << " ";

        int n = nums.size();

        int sum1 = nums[0] * nums[1] * nums[n - 1];
        int sum2 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        return sum1 > sum2 ? sum1 : sum2;
    }
};