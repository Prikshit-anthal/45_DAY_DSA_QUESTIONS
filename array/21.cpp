class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        vector<int> bits(32, 0);
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            addBits(bits, nums[i]);
        }

        n = n / 2 + 1;

        int no = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bits[i] >= n)
            {
                // no+=pow(2,i);
                int curr = 0;
                curr = curr | 1;
                curr = curr << i;
                no = no | curr;
            }
            // cout<<i<<" "<<bits[i]<<endl;
        }

        return no;
    }

    void addBits(vector<int> &bits, int no)
    {
        int i = 0;
        while (no != 0 && i < 32)
        {
            if (no & 1)
            {
                bits[i]++;
            }
            no = no >> 1;
            i++;
        }
    }
};