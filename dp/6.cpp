
class Solution
{
    int X, Y, Z;

public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        X = x, Y = y, Z = z;
        // Your code here
        //  return recursive(n);

        // dp
        vector<int> t(n + 1, -1);
        t[0] = 0;
        return dp(n, t);
    }

    int recursive(int n)
    {
        if (n == 0)
            return 0;

        int i = -1, j = -1, k = -1;
        if (n >= X)
            i = recursive(n - X);

        if (n >= Y)
            j = recursive(n - Y);

        if (n >= Z)
            k = recursive(n - Z);

        if (n < X && n < Y && n < Z)
            return -1;

        int m = max(i, j);
        m = max(m, k);

        if (m == -1)
            return -1;
        else
            return m + 1;
    }

    int dp(int n, vector<int> t)
    {
        for (int i = 1; i <= n; i++)
        {
            int j = -1, k = -1, l = -1;

            if (i >= X)
                j = t[i - X];

            if (i >= Y)
                k = t[i - Y];

            if (i >= Z)
                l = t[i - Z];

            int m = max(j, k);
            m = max(m, l);

            if (m == -1)
                t[i] = -1;
            else
                t[i] = m + 1;
            //   cout<<t[i]<<' ';
        }
        if (t[n] == -1)
            return 0;
        return t[n];
    }
};