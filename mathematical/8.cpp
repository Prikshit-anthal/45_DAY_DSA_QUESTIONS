class Solution
{
public:
    int reverse(int x)
    {
        int digit;
        int a = 0;
        int MAX=INT_MAX;
        int MIN=INT_MIN;

        while (x != 0)
        {
            digit = x % 10;

            if (a > MAX/10 || a < MIN/10)
            {
                return 0;
            }

            if(a==MAX/10)
            {
                if(digit>MAX%10) return 0;
            }

            if(a==MIN/10)
            {
                if(digit<MIN%10) return 0;
            }

            a = a * 10 + digit;
            x = x / 10;
        }
        return a;
    }
};