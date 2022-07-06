class Solution
{
public:
    int kthFactor(int n, int k)
    {

        int i;
        for (i = 1; k != 0 && i <= n; i++)
        {
            if (n % i == 0)
                k--;
        }

        return k == 0 ? --i : -1;
    }
};