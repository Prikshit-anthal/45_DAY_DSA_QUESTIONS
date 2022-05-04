#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;
        int n = prices.size(), arr[n - 1];
        for (int i = 0; i < n - 1; i++)
            arr[i] = prices[i + 1] - prices[i], cout << arr[i] << ' ';
        cout << endl;
        if (n == 2)
            return arr[0] > 0 ? arr[0] : 0;
        int res = max_conti_sub_arr(arr, 0, n - 2);
        cout << res << endl;
        return res;
    }

    int max_conti_sub_arr(int arr[], int s, int e)
    {
        int v =arr[s];
        if (s == e)
            return v;

        int left = max_conti_sub_arr(arr, s, (e + s - 1) / 2);

        int right = max_conti_sub_arr(arr, (e + s - 1) / 2 + 1, e);

        int cross = max_cross_arr(arr, s, e, (e + s - 1) / 2);

        cout << left << " " << right << " " << cross << " " << s << " " << e << endl;

        if (left >= right && left >= cross)
            return left;
        else if (right >= left && right >= cross)
            return right;
        else
            return cross;
    }

    int max_cross_arr(int arr[], int s, int e, int m)
    {
        int max_left = 0;
        int sum = 0;
        int r = m;
        for (int i = m; i >= s; i--)
        {
            sum += arr[i];
            if (sum > max_left)
            {
                r = i;
                max_left = sum;
            }
        }

        int max_right = 0;
        int sum1 = 0;
        int l = m;
        for (int i = m + 1; i <= e; i++)
        {
            sum1 += arr[i];
            if (sum1 > max_right)
            {
                l = i;
                max_right = sum1;
            }
        }

        int v = max_right + max_left;
        return v;
    }
};

int main()
{
    Solution obj;
    vector<int> v =
        {2, 1, 2, 1, 0, 0, 1};
    cout << obj.maxProfit(v);

    return 0;
}

//TLE coming