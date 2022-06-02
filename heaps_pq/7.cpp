class Solution
{
    int n;
    vector<int> ans;

public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {

        int idx = -1;
        n = nums.size();

        while (k--)
            idx = findMinInSubArr(idx + 1, n - k - 1, nums);

        return ans;
    }

    int findMinInSubArr(int start, int end, vector<int> &nums)
    {
        long long min = 1e9 + 1;
        int min_idx = -1;

        cout << start << " " << end << endl;

        for (int i = start; i <= end; i++)
        {
            if (nums[i] < min)
            {
                min = nums[i];
                min_idx = i;
            }
        }
        ans.push_back(min);
        return min_idx;
    }
};

/// TLEEEEEEE