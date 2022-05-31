class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {

        // code here
        long long product = 1, prod_without_zero = 1;
        int count_zero = 0;
        for (auto i : nums)
        {
            product *= i;
            if (i != 0)
                prod_without_zero *= i;
            else
                count_zero++;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0 && count_zero == 1)
            {
                nums[i] = prod_without_zero;
                continue;
            }
            if (count_zero > 0)
                nums[i] = 0;
            if (count_zero == 0)
                nums[i] = product / nums[i];
        }
        return nums;
    }
};