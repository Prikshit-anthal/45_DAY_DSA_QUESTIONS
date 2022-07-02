class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s;
        map<int, int> m;

        int n = nums1.size();
        int mm = nums2.size();

        for (int i = 0; i < mm; i++)
        {
            while (!s.empty())
            {
                if (nums2[s.top()] < nums2[i])
                {
                    m[nums2[s.top()]] = i;
                    s.pop();
                }
                else
                {
                    break;
                }
            }

            s.push(i);
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (m.find(nums1[i]) != m.end())
                ans.push_back(nums2[m[nums1[i]]]);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};