class Solution
{
public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        int ex[10] = {0};
        for (int i = 0; i < n; i++)
            ex[arr[i]]++;

        int j = 0;
        for (int i = 0; i < 10; i++)
        {
            int count = 0;
            for (; count < ex[i]; count++)
                arr[j] = i, j++;
        }

        // for(int i=0;i<10;i++) cout<<ex[i]<<" ";

        long long int ans = 0;
        bool carry = false;
        int zero_count = 0;
        int start = true;

        int i = 0;

        if (n % 2 == 1)
        {
            ans = arr[0];
            i = 1;
        }

        for (; i < n; i += 2)
        {
            int first = 0, second = 0;

            first = arr[i];
            second += arr[i + 1];
            ans = (ans * 10) + (first + second);
        }

        return ans;
    }
};