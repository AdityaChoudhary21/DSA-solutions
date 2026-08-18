class Solution {
public:
    int studentallo(vector<int> &nums, int pages){
        int student = 1;
        int pagestudent = 0;
        for(int i = 0; i<nums.size(); i++){
            if(pagestudent + nums[i] <= pages){
                pagestudent+=nums[i];
            }
            else{
                student++;
                pagestudent=nums[i];
            }
        }
        return student;
        
    }
    int findPages(vector<int> &nums, int m)  {
        if(m>nums.size()){
            return -1;
        }
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(studentallo(nums, mid)>m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& a, int k) {
        return findPages(a, k);
        
    }
};
