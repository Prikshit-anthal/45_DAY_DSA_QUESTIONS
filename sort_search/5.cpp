#include<bits/stdc++.h>
using namespace std;

bool checkReverse(int arr[], int n)
{
    bool inc_dec=true;
    //true==increasing
    //false== dec
    bool second_phase=false;
    int f=-1;
   for(int i=1;i<n;i++)
   {
        //decreasing phase
        if(arr[i]<arr[i-1] && inc_dec)
        {
            if(second_phase)
            return false;
            inc_dec=false;

            //compare 1 ke liye
            f=i-2;
        }

        ///inc phase
        if (arr[i] > arr[i - 1] && !inc_dec)
        {
            if(!second_phase){
            second_phase=true;
            if(arr[i-1]<arr[f])
            return false;
            }

            else{
                inc_dec=true;
            }

        }

        if(second_phase)
        {
            if(arr[i]<arr[f+1])
            {
                return false;
            }
            
        }


   }
   return true;
}

int main()
{
    int arr[] = {1,2,5,4,3,6,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    checkReverse(arr, n) ? cout << "Yes" : cout << "No";
    return 0;
}