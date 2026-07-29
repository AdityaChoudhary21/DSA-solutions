class Solution {
public:
    int largestElement(vector<int>& nums) {
        int maxE=INT_MIN;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]>maxE){
                maxE=nums[i];
            }

        }
        return maxE;

    }
};
