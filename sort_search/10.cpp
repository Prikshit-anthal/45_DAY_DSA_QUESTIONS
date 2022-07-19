class Solution
{
public:
    // Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    {
        // code here
        int n = N;
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += A[i];

        int min = A[n - 1];
        int max = sum;

        // cout<<min<<" "<<max<<' ';
        int ans = binarySearch(min, max, A, n, M);
        return ans;
    }

    int binarySearch(int l, int r, int arr[], int n, int M)
    {
        if (l <= r)
        {
            int mid = l + (r - l) / 2;
            // cout<<" m "<<mid<<" ";
            bool check = isValid(mid, arr, n, M);
            // cout<<check<<endl;
            if (check)
            {
                return binarySearch(l, mid - 1, arr, n, M);
            }
            else
            {
                return binarySearch(mid + 1, r, arr, n, M);
            }
        }
        return l;
    }

    bool isValid(int mid, int arr[], int n, int M)
    {
        int idx = 0;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += arr[i];

            if (s > mid)
            {
                M--;
                s = arr[i];
            }
        }
        if (M >= 1)
            return true;

        return false;
    }
};