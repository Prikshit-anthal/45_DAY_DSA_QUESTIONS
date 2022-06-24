class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        vector<int> sum;
        int n = cardPoints.size();
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += cardPoints[i];
            sum.push_back(s);
        }

        if (k >= n)
            return sum[n - 1];

        int max = -1;
        for (int i = k; i >= 0; i--)
        {
            // last se i utha
            int last = sum[n - 1] - sum[n - i - 1];
            int first = (i == k ? 0 : sum[k - i - 1]);

            if (last + first > max)
                max = last + first;
        }

        return max;
    }
};