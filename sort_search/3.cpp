int binarySearch(int l, int r, int arr[], int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(l, mid - 1, arr, x);

        if (arr[mid] < x)
            return binarySearch(mid + 1, r, arr, x);
    }
    return -1;
}

bool findPair(int arr[], int size, int n)
{
    // code
    sort(arr, arr + size);
    for (int i = 0; i < size; i++)
    {
        int x = arr[i] - n;
        if (x < 0)
            x = arr[i] + n;

        int ans = binarySearch(0, size - 1, arr, x);
        if (ans != -1)
        {
            if (x == arr[i])
            {
                if (i != 0)
                {
                    int j = i - 1;
                    if (arr[j] == arr[i])
                        return true;
                }
                if (i != size - 1)
                {
                    int j = i + 1;
                    if (arr[j] == arr[i])
                        return true;
                }
            }
            else
                return true;
        }
    }
    return false;
}