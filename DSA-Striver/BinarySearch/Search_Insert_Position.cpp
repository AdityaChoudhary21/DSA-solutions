class Solution {
public:
    int bins(vector<int>& nums, int target, int low, int high){
        int mid=low + (high - low)/2;
        if(low>high){
            return low;
        }
        
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return bins(nums,target,low,mid-1);
        }
        else{
            return bins(nums,target,mid+1,high);
        } 
        
    }

    int searchInsert(vector<int>& nums, int target) {
        return bins(nums,target,0,nums.size()-1);
        
    }
};
