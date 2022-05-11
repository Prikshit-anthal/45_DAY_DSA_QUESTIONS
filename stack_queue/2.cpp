#include <iostream>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int count1 = 0, count2 = 0;
        int i, j;
        for (i = s.length() - 1, j = t.length() - 1; i >= 0 && j >= 0; i--, j--)
        {
            cout<<" i "<<i<<" "<<j<<endl;
            if (s[i] == '#')
            {

                count1++;
            }
            else
            {
                if (count1 != 0)
                {
                    count1--;
                }
                else if (count1 == 0 && count2 == 0 && t[j] != '#')
                {
                    if (s[i] != t[j])
                        return false;
                    continue;
                }
                else
                {
                    i++;
                }
            }

            if (t[j] == '#')
            {
                count2++;
            }
            else
            {
                if (count2 != 0)
                {
                    count2--;
                }
                else
                {
                    j++;
                }
            }
        }
        //completing j
        if(j!=0)
        {
            for(;j>=0;j--)
            {
            
                if (t[j] == '#')
                {
                    count2++;
                }
                else
                {
                    if (count2 != 0)
                    {
                        count2--;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if (i != 0)
        {
            for (; i >= 0; i--)
            {
                if (t[i] == '#')
                {
                    count1++;
                }
                else
                {
                    if (count1 != 0)
                    {
                        count1--;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
            return true;
      
    }
};

int main()
{
    Solution obj;
    cout << obj.backspaceCompare("y#fo##f", "y#fx#o##f");
    return 0;
}