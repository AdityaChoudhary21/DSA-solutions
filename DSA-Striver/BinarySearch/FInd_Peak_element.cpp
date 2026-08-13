class Solution {
public:
    int bins(vector<int>& nums, int low, int high){
        if(low==high){
            return low;
        }

        int mid = low + (high - low) / 2;
    
        if(nums[mid]<nums[mid+1]){
            return bins(nums, mid+1, high); 
        }
        else{
            return bins(nums, low, mid);
        }
    }
    int findPeakElement(vector<int>& nums) {
        return bins(nums, 0, nums.size()-1);
        
    }
};




