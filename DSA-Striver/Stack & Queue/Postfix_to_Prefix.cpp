class Solution {
public:
    string postToPre(string s) {
        int i =0;
        stack<string> st;
        while(i<s.length())
        {
            char c = s[i];
            if (isalnum(c))
            {
                st.push(string(1,c));
            }

            else
            {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();

                st.push(c + t2 + t1);
            }
            i++;
        }
        return st.top();
    }
};

