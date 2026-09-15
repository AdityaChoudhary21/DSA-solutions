class Solution {
public:
    vector<int> findnse(const vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nse(n);

        for (int i = n - 1; i >= 0; i--) {
            // Strict inequality here to handle duplicates cleanly with findpse
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            // If no smaller element on the right, boundary is n
            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> findpse(const vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> pse(n);

        for (int i = 0; i < n; i++) {
            // Strict '>' to prevent double counting of duplicate elements
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            // If no smaller element on the left, boundary is -1
            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        int mod = 1e9 + 7;

        vector<int> pse = findpse(arr);
        vector<int> nse = findnse(arr);

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long ways = (left * right) % mod;
            long long contribution = (ways * arr[i]) % mod;

            total = (total + contribution) % mod;
        }

        return total;
    }
};

