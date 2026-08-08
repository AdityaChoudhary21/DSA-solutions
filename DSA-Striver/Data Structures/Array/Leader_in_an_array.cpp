class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n=nums.size();
        int Max=INT_MIN;
        vector<int> ans;
        for(int i=n-1; i>=0; i--){
            if(nums[i]>Max){
                ans.push_back(nums[i]);
                Max=max(Max,nums[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;

      
    }
};
