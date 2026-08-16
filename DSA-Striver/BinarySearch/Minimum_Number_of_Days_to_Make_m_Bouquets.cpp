class Solution {
public:
    int possible(vector<int>& nums,int day ,int m, int k){
        int n = nums.size();
        int cnt=0;
        int nofb=0;
        for(int i = 0 ; i<n; i++){
            if(nums[i]<=day){
                cnt++;
            }
            else{
                nofb += (cnt/k);
                cnt=0;
            }
        }
        nofb += (cnt/k);
        return nofb;
        
        
    }
    int bins(vector<int>& nums, int m, int k, int low, int high, int ans){
        if(low>high){
            return ans;
        }
        int mid = low + (high - low) / 2;
        int func = possible(nums, mid , m, k);
        if(func>=m){
            return bins(nums, m, k, low, mid-1, mid);
        }
        else{
            return bins(nums, m, k, mid+1, high, ans);
        }

    }
    int minDays(vector<int>& nums, int m, int k) {
        long long totalFlowersNeeded = (long long)m * k;
        if (totalFlowersNeeded > nums.size()) {
            return -1;
        }
        int max_nums = *max_element(nums.begin(), nums.end());
        int min_nums = *min_element(nums.begin(), nums.end());
        return bins(nums, m, k, min_nums, max_nums, -1);
        
    }
};
