class Solution {
public:
    int bins(vector<int>& nums, int target, int low, int high){
        if(low>high){
            return target;
        }
        int mid = low + ( high - low) / 2;

        if(nums[low]<=nums[mid]){
            return bins(nums, target=min(target,nums[low]), mid+1, high);
        }
        else{
            return bins(nums, target=min(target,nums[mid]), low, mid-1);
        }
    }
    int findMin(vector<int>& nums) {
        return bins(nums,INT_MAX,0,nums.size()-1);
        
    }
};
