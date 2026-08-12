class Solution {
public:
    int bins(vector<int>& nums, int target, int low, int high){
        if(low>high){
            return -1;
        }
        int mid = low + ( high - low) / 2;

        if(nums[mid]==target){
            return mid;
        }

        if(nums[low]<=nums[mid]){
            if(target>=nums[low] && target<=nums[mid]){
                return bins(nums, target, low, mid-1);
            }
            else{
                return bins(nums, target, mid+1, high);
            }
        }
        else{
            if(target>=nums[mid] && target<=nums[high]){
                return bins(nums, target, mid+1, high);
            }
            else{
                return bins(nums, target, low, mid-1); 
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return bins(nums,target,0,nums.size()-1);
        
    }
};
