class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;

        int old1 = 0;
        ans.push_back(old1);
        for (int i = 0; i < n; i++)
        {
            int curr = i;

            int count = 0;
            // finding first 0
            while (1)
            {
                int x = curr & 1;

                if (x == 0)
                    break;
                count++;
                curr = curr >> 1;
            }

            old1 = old1 - count + 1;
            ans.push_back(old1);
        }

        return ans;
    }
};