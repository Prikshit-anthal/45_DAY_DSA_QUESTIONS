class Solution
{
public:
    bool isPalindrome(int x)
    {

        if (x < 0)
            return false;

        int len = 0;
        int no = x;
        while (no != 0)
        {
            len += 1;
            no = no / 10;
        }

        no = x;
        int temp = pow(10, len - 1);

        while (no != 0)
        {
            int last = no % 10;

            int first = no / temp;

            if (first != last)
                return false;

            no = no % temp;
            no /= 10;

            len -= 2;
            temp /= 100;
        }

        return true;
    }
};