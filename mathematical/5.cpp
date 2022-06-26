class Solution
{
public:
    bool isHappy(int n)
    {
        int arr[10] = {0, 1, 0, 0, 0, 0, 0, 1, 0, 0};

        while (n / 10 != 0)
        {
            int neew = 0;
            while (n != 0)
            {
                neew += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = neew;
        }

        if (arr[n] == 0)
            return false;
        else
            return true;
    }
};

// single digit pr lao
// only 1 and 7 pr hota hai else all infinite loop