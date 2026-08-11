class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int sum = 0;
        int maxlen=0;
        int n= nums.size();
        int i=0;
        for(int j=0; j<n; j++){
            sum+=nums[j];
            if(sum==k){
                maxlen=max(maxlen,j-i+1);
            }
            if(sum>k){
                sum-=nums[i];
                i++;
            }

        }
        return maxlen;
    }
};
