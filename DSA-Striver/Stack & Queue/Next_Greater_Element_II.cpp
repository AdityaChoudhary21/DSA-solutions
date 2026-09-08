class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i = 2*n-1; i>=0; i--){
            int num = nums[i%n];

            while(!st.empty() && st.top()<= num){
                st.pop();
            }
            if(i<n){
                nge[i] = st.empty() ? -1 : st.top();
                
            }
            st.push(num);
        }
        
        return nge;
        
    }
};
