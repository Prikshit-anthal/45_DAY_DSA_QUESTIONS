class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        map<int, vector<int>> m;
        for (auto i : adjacentPairs)
        {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }

        int idx;
        int prev = -1e9;

        for (auto i : m)
        {
            if (i.second.size() == 1)
            {
                idx = i.first;
                break;
            }
        }

        vector<int> ans;

        while (1)
        {
            ans.push_back(idx);

            if (m[idx].size() == 1 && prev == m[idx][0])
            {

                break;
            }
            else if (prev == -1e9)
            {

                prev = idx;
                idx = m[idx][0];
            }
            else
            {
                int previ = idx;
                cout << "Prev " << prev;
                if (m[idx][0] == prev)
                {
                    idx = m[idx][1];
                }
                else
                {
                    idx = m[idx][0];
                }
                prev = previ;
            }
        }

        return ans;
    }
};