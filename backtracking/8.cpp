class Solution
{
    int n;
    vector<vector<int>> ans;

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        unordered_map<int, int> m;
        n = nums.size();

        for (int i = 0; i < n; i++)
            m[nums[i]]++;

        vector<int> se;
        backTrack(m, se);

        return ans;
    }

    void backTrack(unordered_map<int, int> &m, vector<int> &taken)
    {

        bool found = false;
        // choose konsa lena
        for (auto i : m)
        {
            if (i.second > 0)
            {

                found = true;
                m[i.first]--; ////se dont use m.erase(i.first);
                              /// iterations problem in unordered map
                taken.push_back(i.first);

                // cout<<i.first<<" ";

                backTrack(m, taken);
                taken.pop_back();
                m[i.first]++;
            }
        }
        if (!found)
        {
            ans.push_back(taken);
        }
    }
};