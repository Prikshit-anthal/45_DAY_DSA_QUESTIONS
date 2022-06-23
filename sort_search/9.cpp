class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        return binarySearch(0,nums.size()-1,nums);
        
    }
    
    int binarySearch(int l,int r,vector<int>& nums)
    {
        if(r>=l){
       int m=l+(r-l)/2;
       
        
        if(m==0 || m==nums.size()-1)
        {
            if(nums.size()==1) return 0;
            if(m==0)
            {
                if(nums[m]>nums[m+1]) return m;
            }
            if(m==nums.size()-1) 
            {
                if(nums[m]>nums[m-1]) return m;
            }
        }
       else if(nums[m]>nums[m-1] && nums[m]>nums[m+1])
        {
            return m;
        }
            
           int s= binarySearch(l,m-1,nums);
            int p= binarySearch(m+1,r,nums);
            
            if(s!=-1)
                return s;
            if(p!=-1)
                return p;
            
            }
        
        return -1;
    }
};