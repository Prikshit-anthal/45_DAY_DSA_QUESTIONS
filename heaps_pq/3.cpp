#include<bits/stdc++.h>
using namespace std;

class Solution
{
    unsigned long long arr[1690] = {};
    int idx = 0;

public:
    int nthUglyNumber(int n)
    {
        return arr[n - 1];
    }
    Solution()
    {
        int count = 0;
        int cur = 1;
        while (idx < 1690)
        {
            unsigned long long _2 = 1, _3 = 1, _5 = 1;

            unsigned long long curr = cur;

            while (curr % 2 == 0)
            {
                _2 *= 2;
                curr/=2;
            }
            curr = cur;
            while (curr % 3 == 0)
            {
                _3 *= 3;
                curr /= 3;
            }
            curr = cur;
            while (curr % 5 == 0)
            {
                _5 *= 5;
                curr /= 5;
            }

            if (_2 * _3 * _5 == cur)
            {
                arr[idx] = cur;
                idx++;
            }

            cur++;
        }
    }
};

int main()
{

  Solution obj;
  for(int i=1;i<=20;i++)
  cout<<obj.nthUglyNumber(i)<<endl;
    return 0;
}