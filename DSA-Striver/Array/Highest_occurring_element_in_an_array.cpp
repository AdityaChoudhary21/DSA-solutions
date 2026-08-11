class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        map<int,int> freq;

        for (int i : nums){
            freq[i]++;
        }
        

        
        int largest = INT_MIN;  
        int ans = 0;

        for(auto p : freq){
                 
            if (p.second > largest){
            largest=p.second;
            ans = p.first;
            }
            
        }
        return ans;
    }
};