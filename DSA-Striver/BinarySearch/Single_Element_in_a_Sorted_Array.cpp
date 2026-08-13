class Solution {
public:
    int bins(vector<int>& nums, int low, int high){
        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        int mid = low + (high - low) / 2;
        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
            return nums[mid];
        }
        if(mid % 2 == 1 && nums[mid]==nums[mid-1] || mid % 2 == 0 && nums[mid]==nums[mid+1]){
            return bins(nums, mid+1, high);
        }
        else{
            return bins(nums, low, mid-1);
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        return bins(nums, 1, nums.size()-2);
    }
};

