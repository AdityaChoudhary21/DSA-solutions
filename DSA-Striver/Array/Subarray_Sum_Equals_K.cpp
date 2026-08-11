class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int maxS=0;
        int n= nums.size();
        unordered_map<int, int> prefixCnt;
        prefixCnt[0]=1;
        for(int i=0; i<n; i++){
            sum+=nums[i];

            if(prefixCnt.find(sum-k)!=prefixCnt.end()){
                maxS+=prefixCnt[sum-k];
            }

            prefixCnt[sum]++;

        }
        return maxS;
    }
        
};


