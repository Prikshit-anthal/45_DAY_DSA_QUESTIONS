class Solution {
    int n;
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        n=nums.size();
                
       vector<int> temp;
       ans.push_back(temp);
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            backTrack(i,nums,temp);
        }
        
        return ans;
    }
    
    void backTrack(int i,vector<int> & nums,vector<int> temp)
    {
        temp.push_back(nums[i]);
        ans.push_back(temp);
        
        for(int j=i+1;j<n;j++)
        {
            if(j>i+1 && nums[j]==nums[j-1])
                continue;
            
            backTrack(j,nums,temp);
        }
    }
};