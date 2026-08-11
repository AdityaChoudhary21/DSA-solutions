class Solution{
public:
    int bins(vector<int> &nums, int x, int low, int high,int ans){
        if(low>high){
            return ans;
        }

        int mid = low + (high - low) / 2;
        if(nums[mid]>=x){
            return bins(nums, x, low, mid-1, mid);
        }
        else{
            return bins(nums, x, mid+1, high, ans);
        }
    }
    int lowerBound(vector<int> &nums, int x){
        return bins(nums,x,0,nums.size()-1,nums.size());
        
    }
};
