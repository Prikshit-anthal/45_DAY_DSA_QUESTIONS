bool comparator(int x,int y){
       if(x>y)
       return true;
       return false;
   }
class Solution {
  public:
  
    bool isPossible(long long a[], long long b[], long long n, long long k) {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+n,comparator);
        
        while(--n)
        {
            if(a[n]+b[n]<k)
            return false;
        }
        return true;
        
    }
};