class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {

        vector<int> sum;
        int n = nums.size();
        int s = 0;
        sum.push_back(0);
        for (int i = 0; i < n; i++)
            s += nums[i], sum.push_back(s);

        unordered_map<int, int> m;
        int count = 0;
        m[0] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            int remainder = sum[i] % k;
            if (remainder < 0)
                remainder = -remainder;
            count += m[remainder];
            m[remainder]++;
        }

        return count;
    }
};