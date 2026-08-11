class Solution {
public:
    int bins(vector<int>& nums, int target, int low, int high){
        if(low>high){
            return -1;
        }
        int mid=(low+high)/2;
        
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
    int search(vector<int>& nums, int target) {
        return bins(nums,target,0,nums.size()-1);

        
    }
};
