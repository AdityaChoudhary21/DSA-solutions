class Solution {
public:
    int sum(vector<int>& nums, int t, int divisor){
        int n = nums.size();
        long long d=0;
        for(int i = 0; i<n; i++){
            d+= ceil((double)nums[i] / divisor);
        }
        return d;


    }
    int smallestDivisor(vector<int>& nums, int t) {
        int n = nums.size();
        int k = *max_element(nums.begin(), nums.end());

        int low = 1, high = k;
        int ans=INT_MAX;

        while (low<=high){
            int mid = low + (high - low) / 2;
            int func = sum(nums, t, mid);
            if(func<=t){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return ans;
        
    }
};

