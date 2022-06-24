class Solution
{
public:
    int reverse(int x)
    {
        int digit;
        int a = 0;
        while (x != 0)
        {
            digit = x % 10;

            if (a > INT_MAX / 10 || a < INT_MIN / 10)
            {
                return 0;
            }

            a = a * 10 + digit;
            x = x / 10;
        }
        return a;
    }
};