class Solution {
public:

    int function(vector<int>& nums , int low , int high ){
        int pivot = nums[low];
        int i = low;
        int j = high;
        while(i<j){
            while(nums[i]<=pivot && i<=high-1){
                i++;
            }
            while(nums[j]>pivot && j>=low+1){
                j--;
            }
            if(i<j) swap(nums[i],nums[j]);
        }
        swap(nums[low],nums[j]);
        return j;


    }
    void qs(vector<int>& nums , int low , int high){
        if(low<high){
            int pindex = function(nums, low , high);
            qs(nums, low, pindex-1);
            qs(nums, pindex+1, high);
        }
        
    }
    vector<int> quickSort(vector<int>& nums) {
        int n = nums.size();
        qs(nums, 0 , n-1);
        return nums;

    }
};
