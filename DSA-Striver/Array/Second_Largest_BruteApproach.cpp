class Solution {
public:
    
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[low];
        int i=low;
        int j= high;
        while(nums[i]<=pivot && i<=high-1){
            i++;
        }
        while(nums[j]>=pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(nums[i],nums[j]);
        }
        swap(nums[low],nums[j]);
        return j;
    }
    void qs(vector<int>& nums, int low, int high){
        if(low<high){
            int pindex=partition(nums, low, high);
            qs(nums, low, pindex-1);
            qs(nums, pindex+1, high);
        }
        
    }
    
    int secondLargestElement(vector<int>& nums) {
        int n=nums.size();
        qs(nums, 0, n-1);
        for(int i=n-2;i>=0;i--){
            if(nums[i]!=nums[n-1]){
                return nums[i];
            }
        }
        return -1;

        
      
    }
};
