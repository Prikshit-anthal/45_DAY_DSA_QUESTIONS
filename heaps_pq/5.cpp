#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comparator(pair<int, int> i, pair<int, int> j)
    {
        return i.second > j.second ? true : false;
    }
    string reorganizeString(string s)
    {

        vector<pair<int, int>> alpha(26, {-1, 0});

        for (auto curr : s)
        {
            int x = curr - 97;
            alpha[x].first = x;
            alpha[x].second++;
        }

        sort(alpha.begin(), alpha.end(), comparator);

        int f_i = 0;
        int s_i = 1;

        string ans;

        if (alpha[s_i].first != -1)
        {

            while (1)
            {
                char curr = alpha[f_i].first + 97;

                ans.push_back(curr);
                curr = alpha[s_i].first + 97;

                ans.push_back(curr);
                
                cout<<ans<<endl;

                alpha[f_i].second--;
                alpha[s_i].second--;

                if (alpha[f_i].second == 0)
                {
                    f_i = findNext(f_i, alpha, s_i);
                }

                if (alpha[s_i].second == 0)
                {
                    s_i = findNext(s_i, alpha, f_i);
                }

                if (s_i == -1 && f_i == -1)
                    return ans;

                if (s_i == -1)
                {
                    if (alpha[f_i].second > 1)
                        return "";

                    curr = alpha[f_i].first + 97;
                    ans.push_back(curr);

                    return ans;
                }

                if (f_i == -1)
                {
                    if (alpha[s_i].second > 1)
                        return "";

                    curr = alpha[s_i].first + 97;
                    ans.push_back(curr);

                    return ans;
                }
            }
        }

        else
        {
            if (alpha[f_i].second > 1)
            {
                return "";
            }
            return s;
        }
    }

    int findNext(int curr, vector<pair<int, int>> alpha, int sec)
    {
        curr++;
        while (curr < 26)
        {

            if (alpha[curr].second != 0 && curr != sec)
                return curr;
        curr++;
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    cout<<obj.reorganizeString("aab");

    return 0;
}