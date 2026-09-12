class Solution {
public:
    string postToInfix(string s) 
    {
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
                string con = "(" + t2 + c + t1 + ")";

                st.push(con);
            }
            i++;
        }
        return st.top();
    }
};


