class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i = n-1; i>=0; i--){
            int num = nums[i];

            while(!st.empty() && st.top()>=num){
                st.pop();
            }

            nge[i] = st.empty() ? -1 : st.top();

            st.push(num);
        }
        
        return nge;
    }
};
