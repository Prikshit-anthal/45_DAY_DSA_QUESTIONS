class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        map<int, vector<int>> m;
        int n = temperatures.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
            m[temperatures[i]].push_back(i + 1);

        for (int i = 0; i < n; i++)
        {
            int curr = temperatures[i];
            int min_count = 1e9;
            curr++;

            while (curr <= 100)
            {
                if (m.find(curr) == m.end())
                {
                    curr++;
                    continue;
                }

                // for(auto val:m[curr])
                // {
                //     if(val>i)
                //     {
                //         if(val<min_count) min_count=val;
                //         break;
                //     }
                // }

                auto idx = upper_bound(m[curr].begin(), m[curr].end(), i) - m[curr].begin();
                if (idx != m[curr].size())
                {
                    if (m[curr][idx] < min_count)
                        min_count = m[curr][idx];
                }

                curr++;
            }

            if (min_count == 1e9)
                min_count = i + 1;

            ans.push_back(min_count - 1 - i);
        }

        return ans;
    }
};




///TLE