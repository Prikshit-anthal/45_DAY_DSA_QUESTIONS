class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int n = height.size();
        int l = 0, r = n - 1;
        int max = (r - l) * min(height[r], height[l]);
        while (r > l)
        {
            int vol = (r - l) * min(height[l], height[r]);
            if (max < vol)
                max = vol;

            int new_l = l, new_r = r;

            if (height[l] < height[r])
            {
                new_l = findNext(l, 'r', n, height);
            }
            else
            {
                new_r = findNext(r, 'l', n, height);
            }

            if (new_l == -1 || new_r == -1)
                break;

            l = new_l;
            r = new_r;
        }
        return max;
    }

    int findNext(int idx, char direction, int n, vector<int> &height)
    {
        int start, end;
        int idxx = idx;

        while (idxx >= 0 && idxx < n)
        {
            if (height[idxx] > height[idx])
                return idxx;

            if (direction == 'l')
                idxx--;
            else
                idxx++;
        }
        return -1;
    }
};