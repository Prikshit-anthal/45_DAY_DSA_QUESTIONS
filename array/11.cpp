#include <bits/stdc++.h>
using namespace std;

// nlgn complexity
int findMinDiff(int arr[], int n, int m)
{
    sort(arr, arr + n);
    int min_diff = 1e9;
    for (int i = 0; i < n - m + 1; i++)
    {
        if (arr[m + i - 1] - arr[i] < min_diff)
            min_diff = arr[m + i - 1] - arr[i];
    }
    return min_diff;
}

int main()
{
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30,
                 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0;

    return 0;
}