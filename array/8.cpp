#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        int n = nums.size();
        vector<pair<int, int>> sort_me;
        for (int i = 0; i < n; i++)
            sort_me.push_back({nums[i], i});
        sort(sort_me.begin(), sort_me.end());
        for (int i = 0; i < n; i++)
        {
            if (target == 2 * sort_me[i].first)
            {
                if (sort_me[i + 1].first != sort_me[i].first)
                {
                    continue;
                }
                else
                {
                    vector<int> v = {sort_me[i].second, sort_me[i + 1].second};
                    // vector <int> v;
                    return v;
                }
            }
            int idx = binarySearch(sort_me, 0, n, target - sort_me[i].first);
            // cout<<idx<<endl;
            if (idx != -1)
            {
                // cout<<nums.begin()-lower;
                vector<int> v = {sort_me[idx].second, sort_me[i].second};
                // vector <int> v;
                return v;
            }
        }
        vector<int> v;
        return v;
    }
    int binarySearch(vector<pair<int, int>> &arr, int l, int r, int x)
    {
        if (r >= l)
        {
            int mid = l + (r - l) / 2;

            // If the element is present at the middle
            // itself
            if (arr[mid].first == x)
                return mid;

            // If element is smaller than mid, then
            // it can only be present in left subarray
            if (arr[mid].first > x)
                return binarySearch(arr, l, mid - 1, x);

            // Else the element can only be present
            // in right subarray
            return binarySearch(arr, mid + 1, r, x);
        }

        // We reach here when element is not
        // present in array
        return -1;
    }
};

int main()
{
    vector<int> v = {1, 6142, 8192, 10239};
    Solution obj;
    cout << obj.twoSum(v, 18431)[0] << obj.twoSum(v, 18431)[1];
    return 0;
}

///runtime error