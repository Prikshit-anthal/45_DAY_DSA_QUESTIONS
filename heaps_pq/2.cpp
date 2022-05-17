bool comparator(int x,int y)
{
return x>y?true:false;
}
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),comparator);
            return nums[k-1];
            
    }
};