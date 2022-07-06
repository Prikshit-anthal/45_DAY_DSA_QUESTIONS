class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int i = 0, j = 1; // prev and forward idx
        int count = 0;

        // sort
        sort(intervals.begin(), intervals.end());

        while (j < intervals.size())
        {
            // overlap encountered
            if (intervals[i][1] > intervals[j][0])
            {

                count++;

                // j wala engulf case
                if (intervals[j][1] <= intervals[i][1])
                {
                    i = j;
                }
            }
            else
            {
                // no overlap encountered
                i = j;
            }
            j++;
        }
        return count;
    }
};