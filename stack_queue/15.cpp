class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        // Your code here
        int remaining_dist = 0;
        int curr_dist = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            curr_dist += p[i].petrol - p[i].distance;
            if (curr_dist < 0)
            {
                start = i + 1;
                remaining_dist += curr_dist;
                curr_dist = 0;
            }
        }

        return curr_dist + remaining_dist >= 0 ? start : -1;
    }
};