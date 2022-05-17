class Solution
{
public:
    string addBinary(string a, string b)
    {
        int na = a.length();
        int nb = b.length();
        string final;
        int carry = 0;
        int i, j;
        for (i = 0, j = 0; i < a.length() && j < b.length(); i++, j++)
        {
            if (a[na - 1 - i] == b[nb - 1 - j])
            {
                if (carry == 0)
                    final.push_back('0');
                else
                    final.push_back('1');

                if (a[na - 1 - i] == '1')
                {
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
            }
            else
            {
                if (carry == 0)
                {
                    final.push_back('1');
                }
                else
                {
                    final.push_back('0');
                    carry = 1;
                }
            }
        }
        if (i != a.length())
        {
            for (; i < a.length(); i++)
            {
                if (carry == 0)
                    final.push_back(a[na - 1 - i]);
                else
                {
                    if (a[na - 1 - i] == '1')
                        final.push_back('0');
                    else
                    {
                        final.push_back('1');
                        carry = 0;
                    }
                }
            }
        }
        if (j != b.length())
        {
            for (; j < b.length(); j++)
            {
                if (carry == 0)
                    final.push_back(b[nb - 1 - j]);
                else
                {
                    if (b[nb - 1 - j] == '1')
                        final.push_back('0');
                    else
                        final.push_back('1'), carry = 0;
                }
            }
        }
        if (carry)
            final.push_back('1');
        reverseStr(final);
        return final;
    }
    void reverseStr(string &str)
    {
        int n = str.length();

        // Swap character starting from two
        // corners
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }
};