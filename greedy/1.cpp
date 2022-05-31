#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        int n = gas.size();
        for (int i = 0; i < n; i++)
        {
            if (possible(i, gas, cost) == true)
                return i;
        }

        return -1;
    }

    bool possible(int i, vector<int> &gas, vector<int> &cost)
    {
        bool check=false;
        int idx=i;
        int n=gas.size();
        int tank = 0;
        while (idx!=i || !check)
        {
            if(idx==i)check=true;

            tank += gas[i];
            if (tank < cost[i])
                return false;
            
            tank -= cost[i];

            if(i==n-1) i=0;
            else i++;
        }

        return true;
    }
};

int main()
{
    Solution obj;
    vector<int> gas = { 1, 2, 3, 4, 5 }, cost = {3, 4, 5, 1, 2 };
     cout<<obj.canCompleteCircuit(gas,cost);
    return 0;
}