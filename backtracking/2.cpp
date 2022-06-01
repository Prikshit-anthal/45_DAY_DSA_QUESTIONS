class Solution
{

    // pehle jaisa bs taget =netSum/2;

    int netSum = 0;
    int n;

public:
    int equalPartition(int N, int arr[])
    {
        // code here
        netSum = 0;
        n = N;
        vector<int> temp;

        for (int i = 0; i < N; i++)
            netSum += arr[i];

        if (netSum % 2 == 1)
            return 0;

        sort(arr, arr + N);

        for (int i = 0; i < n; i++)
        {

            /// avoiding case 111111111 type see first 1 has taken all cases of other one's
            // too soo avoiding other one's too redo same task
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            return backTrack(i, arr, netSum / 2, temp);
        }
    }
    int backTrack(int start_idx, int arr[], int target, vector<int> temp)
    {
        int new_target;
        if (arr[start_idx] > target)
        {
            cout << " ret zero " << arr[start_idx] << " ";
            return 0;
        }

        temp.push_back(arr[start_idx]);

        new_target = target - arr[start_idx];

        if (new_target == 0)
        {

            return 1;
        }

        for (int i = start_idx + 1; i < n; i++)
        {

            /// avoiding case 111111111 type see first 1 has taken all cases of other one's
            // too soo avoiding other one's too redo same task
            if (i > start_idx + 1 && arr[i] == arr[i - 1])
                continue;

            if (arr[i] <= new_target)
                if (backTrack(i, arr, new_target, temp) == 1)
                    return 1;
        }
        return 0;
    }
};