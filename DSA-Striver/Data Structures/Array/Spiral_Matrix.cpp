 class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> temp;
        int n = m.size();
        int n1 = m[0].size();
        int left=0, right=n1-1;
        int botm=n-1, top=0;
        while(top<=botm && left<=right){
            for(int i=left ; i<=right; i++){
                temp.push_back(m[top][i]);
            }
            top++;

            for(int i=top ; i<=botm; i++){
                temp.push_back(m[i][right]);
            }
            right--;
            if(top<=botm){
                for(int i=right ; i>=left; i--){
                    temp.push_back(m[botm][i]);
                }
                botm--;
            }
            if(left<=right){
                for(int i=botm ; i>=top; i--){
                    temp.push_back(m[i][left]);
                }
                left++;
            }
                
        }
        return temp;
    }
    
};

 
