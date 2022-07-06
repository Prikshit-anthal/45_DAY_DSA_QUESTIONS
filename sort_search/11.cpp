class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        // Code here
        map<int, int> m;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            m[nums[i]] = i;

        sort(nums.begin(), nums.end());

        // swap sort
        // swaps to convert original -> sorted arr=sorted->original
        int i = 0;
        int swaps = 0;
        while (i < n)
        {
            if (i != m[nums[i]])
            {
                // repacing real array val to its old location
                int temp = nums[m[nums[i]]];
                nums[m[nums[i]]] = nums[i];
                nums[i] = temp;

                swaps++;
            }
            else
            {
                i++;
            }
        }
        return swaps;
    }
};