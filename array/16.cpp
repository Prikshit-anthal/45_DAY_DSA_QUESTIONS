class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        vector<int> sum;
        int n = nums.size();
        int s = 0;

        sum.push_back(0); // 0th idx ke liye
        for (int i = 0; i < n; i++)
        {
            s += nums[i];
            sum.push_back(s);
        }

        int count = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < n + 1; i++)
        {
            if (m.find(sum[i] - k) != m.end())
            {
                count += m[sum[i] - k];
            }

            m[sum[i]]++; /// store count of no of 0 not idx
        }

        return count;
    }
};