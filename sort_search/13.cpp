class Solution
{
    int k, n;

public:
    int search(vector<int> &nums, int target)
    {
        n = nums.size();
        k = binary_search_0_idx(0, n - 1, nums);

        if (k == -1)
        {
            k = n;
        }
        // cout<<k;
        // now binary search se target find
        int idx = binary_search_k_idx(0, n - 1, nums, target);

        return idx;
    }

    int binary_search_0_idx(int l, int r, vector<int> &nums)
    {
        int mid = l + (r - l) / 2;

        if (r >= l)
        {
            // cout<<" m "<<mid<<endl;
            if (mid != r)
            {
                // cout<<" g";
                if (nums[mid + 1] - nums[mid] < 0)
                    return mid + 1;
            }

            if (mid != l)
            {
                // cout<<" gp";
                if (nums[mid] - nums[mid - 1] < 0)
                    return mid;
            }

            int x = binary_search_0_idx(l, mid - 1, nums);
            int y = binary_search_0_idx(mid + 1, r, nums);
            return (x > y) ? x : y;
        }

        return -1;
    }

    int binary_search_k_idx(int l, int r, vector<int> &nums, int target)
    {
        int mid = l + (r - l) / 2;
        // if(l>n-k)
        //     real_l=l-n+k;
        // else
        //     real_l=k+l;

        int real_l = (l > n - 1 - k) ? l - n + k : k + l;
        int real_r = (r > n - 1 - k) ? r - n + k : k + r;
        int real_m = (mid > n - 1 - k) ? mid - n + k : k + mid;

        // cout<<" real mid "<<mid-n+k<<" "<<real_m<<endl;

        if (r >= l)
        {
            if (nums[real_m] == target)
                return real_m;

            else if (target < nums[real_m])
                return binary_search_k_idx(l, mid - 1, nums, target);

            else
                return binary_search_k_idx(mid + 1, r, nums, target);
        }
        return -1;
    }
};