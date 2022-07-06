class Solution
{
    int count = 0;

public:
    int reversePairs(vector<int> &nums)
    {

        mergesort(nums, 0, nums.size() - 1);
        return count;
    }

    void mergesort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, r);

        // now check for double

        int i = l;
        int j = mid + 1;

        while (i <= mid && j <= r)
        {
            long long duble = 2 * (long long)nums[j];

            while (i <= mid && nums[i] <= duble)
                i++;

            // counting here
            count += (mid + 1 - i);

            j++;
        }

        // now merging
        vector<int> temp;

        for (i = l, j = mid + 1; i <= mid && j <= r;)
        {
            if (nums[i] < nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while (i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= r)
        {
            temp.push_back(nums[j]);
            j++;
        }

        // cout<<temp.size()<<endl;
        // for(auto i:temp) cout<<i<<" ";
        // cout<<endl;
        // copyping to original
        for (i = l; i <= r; i++)
        {
            nums[i] = temp[i - l];
            // cout<<temp[i-l]<<" ";
        }
    }
};