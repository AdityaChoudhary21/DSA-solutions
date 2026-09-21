class Solution {
private:
    long long sumSubarrayMins(const vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n), nse(n);
        stack<int> st;

        // Previous Smaller Element (strict inequality to handle duplicates)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long totalMin = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            totalMin += left * right * nums[i];
        }
        return totalMin;
    }

    long long sumSubarrayMaxs(const vector<int>& nums) {
        int n = nums.size();
        vector<int> pge(n), nge(n);
        stack<int> st;

        // Previous Greater Element (strict inequality to handle duplicates)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long totalMax = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            totalMax += left * right * nums[i];
        }
        return totalMax;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};

