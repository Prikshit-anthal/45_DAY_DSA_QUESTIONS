class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {

        for (int i = 0; i < s.length();)
        {
            if (s[i] == '#')
            {
                if (i == 0)
                {
                    s.erase(0, 1);
                }
                else
                {
                    s.erase(i - 1, 2);
                    i--;
                }
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < t.length();)
        {
            if (t[i] == '#')
            {
                if (i == 0)
                {
                    t.erase(0, 1);
                }
                else
                {
                    t.erase(i - 1, 2);
                    i--;
                }
            }

            else
            {
                i++;
            }
        }

        return s == t ? true : false;
    }
};