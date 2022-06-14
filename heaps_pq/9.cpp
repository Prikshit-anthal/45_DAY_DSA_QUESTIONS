class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        // Your code here
        unordered_map<int, pair<int, int>> mp;

        int max_count = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            auto curr = mp[sum];

            if (curr.first == 0 && curr.second == 0 && sum != 0)
                mp[sum] = {i + 1, i + 1};

            else
            {
                mp[sum] = {curr.first, i + 1};
                int count = i + 1 - curr.first;
                if (max_count < count)
                    max_count = count;
            }
        }
        return max_count;
    }
};