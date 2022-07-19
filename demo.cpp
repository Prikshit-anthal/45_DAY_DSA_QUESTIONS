// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int SubsetSum(vector<int> &arr, int sum)
    {
        int t[arr.size() + 1][sum + 1];

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr.size(); j++)
            {
                if (i == 0)
                {
                    t[i][j] = 0;
                }

                if (j == 0)
                {
                    t[i][j] = 1;
                }
            }
        }
        for (int i = 1; i < arr.size(); i++)
        {
            for (int j = 1; j < arr.size(); j++)
            {
                if (arr[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
                }

                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[arr.size()][sum];
    }

    int minDifference(int arr[], int n)
    {

        vector<int> v;
        int ans = INT_MAX;
        int range = 0;
        for (int j = 0; j < n; j++)
        {
            range += arr[j];
        }
        SubsetSum(arr, range);
        int t[arr.size() + 1][range + 1];

        for (int j = 0; j < range / 2; j++)
        {
            if (t[n][j] == true)
            {
                v.push_back(j);
            }
        }

        for (int i = 0; i < range / 2; i++)
        {
            ans = min(range - 2 * v[i], ans);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends