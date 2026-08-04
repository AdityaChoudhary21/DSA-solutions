class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n=nums.size();
        unordered_map<int,int>numMap;

        for(int i=0; i<n; i++){
            int compliment=target-nums[i];
            if(numMap.find(compliment)!=numMap.end()){
                return{numMap[compliment],i};
            }
            numMap[nums[i]]+=i;
        }
        return{};
        
        
    }
};
