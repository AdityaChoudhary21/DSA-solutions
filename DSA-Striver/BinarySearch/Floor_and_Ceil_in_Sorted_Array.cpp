class Solution {
public:
    vector<int> bins(vector<int>& nums, int target, int low, int high,int floor, int ceil){
        int mid=low + (high - low)/2;
        if(low>high){
            return {floor, ceil};
        }
        if(nums[mid]==target){
            return {nums[mid], nums[mid]};
        }
        else if(nums[mid]<target){
            return bins(nums, target,mid+1, high, nums[mid], ceil );
        }
        else{
            return bins(nums,target,low,mid-1, floor, nums[mid]);
        }
        
    }
    vector<int> getFloorAndCeil(vector<int> nums, int target) {
        return bins(nums,target,0,nums.size()-1, -1, -1);
   
    }
};
