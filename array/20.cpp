class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int q = m - 1, w = n - 1, e = m + n - 1;

        while (q >= 0 && w >= 0)
        {
            if (nums1[q] < nums2[w])
                nums1[e--] = nums2[w--];
            else
                nums1[e--] = nums1[q--];
        }

        while (w >= 0)
        {
            nums1[e--] = nums2[w--];
        }
    }
};