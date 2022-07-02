class Solution
{
    int m = 1000000007;

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        vector<int> min_till;
        int n = arr.size();
        int ans = arr[0];

        for (int i = 1; i < n; i++)
        {

            // khudo add i.e. sigle wala
            //  cout<<"adding "<<arr[i]<<endl;
            ans = (ans % m + arr[i]) % m;

            // i-1 waley se comparison
            //  cout<<arr[i]<<" and "<<arr[i-1]<<endl;
            if (arr[i] > arr[i - 1])
                min_till.push_back(arr[i - 1]);
            else
                min_till.push_back(arr[i]);

            int j = min_till.size() - 1;

            int minn = 1e9;
            // i-1 se pehle valo se comparison
            while (j >= 0)
            {
                minn = min(minn, min_till[j]);
                // cout<<"adding "<<minn<<endl;
                ans = (ans % m + minn) % m;
                j--;
            }
        }

        return ans;
    }
};


//TLEE