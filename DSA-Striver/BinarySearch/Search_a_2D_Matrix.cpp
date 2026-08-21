class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int x = target;
        
        int low = 0, high = n*m-1;
        
        while(low<=high){
            int mid = low + (high - low ) / 2;
            int row = mid / m;
            int col = mid % m;
            if(matrix[row][col]==x){
                return true;
            }
            else if(matrix[row][col]>x){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
        
    }
};
