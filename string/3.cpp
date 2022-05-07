class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.length();
        int p = needle.length();
        if (p == 0)
            return 0;
        for (int i = 0; i < n - p + 1; i++)
        {
            if (haystack[i] == needle[0])
            {
                cout << " " << i << endl;
                int j = 1;
                for (j = 1; j < p; j++)
                {
                    if (needle[j] != haystack[i + j])
                        break;
                }
                if (j - 1 == p - 1)
                    return i;
            }
        }
        return -1;
    }
};