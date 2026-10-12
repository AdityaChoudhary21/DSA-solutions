class Solution {
public:
    int maxDepth(string s) 
    {
        int count = 0;
        int maxcnt = 0;
        for (char c : s)
        {
            if(c=='(')
            {
                count++;
            }
            if(c==')')
            {
                maxcnt = max(count,maxcnt);
                count--;
            }
        }
        return maxcnt;
        
    }
};