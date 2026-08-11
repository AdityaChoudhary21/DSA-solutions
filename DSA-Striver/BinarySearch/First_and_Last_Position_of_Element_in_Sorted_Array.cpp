class Solution {
public:
    int lastbins(vector<int>& nums, int target, int low, int high, int last){
        int mid=low + (high - low)/2;
        if(low>high){
            return last;
        }
        
        if(nums[mid]==target){
            return lastbins(nums,target,mid+1,high, mid);
        }
        else if(nums[mid]>target){
            return lastbins(nums,target,low,mid-1, last);
        }
        else{
            return lastbins(nums,target,mid+1,high, last);
        } 
        
    }
    int firstbins(vector<int>& nums, int target, int low, int high, int first){
        int mid=low + (high - low)/2;
        if(low>high){
            return first;
        }
        
        if(nums[mid]==target){
            return firstbins(nums,target,low,mid-1, mid);
        }
        else if(nums[mid]>target){
            return firstbins(nums,target,low,mid-1, first);
        }
        else{
            return firstbins(nums,target,mid+1,high,first);
        } 
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstpos = firstbins(nums,target,0,nums.size()-1, -1);
        int lastpos = lastbins(nums,target,0,nums.size()-1, -1);
        return {firstpos, lastpos};
    }
};
