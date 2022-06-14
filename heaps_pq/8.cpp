class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        // Your code here
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                mp[arr[i]]++;
        }

        int i;
        for (i = 1; i <= n; i++)
        {
            if (mp[i] == 0)
            {
                return i;
            }
        }

        return i;
    }
};