class Solution {
public:
    string prefixToInfix(string s) 
    {
        int i = s.length()-1;
        stack<string> st;
        while(i>=0)
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
                string con = "(" + t1 + c + t2 + ")";

                st.push(con);
            }
            i--;
        }
        return st.top();
    }
};

