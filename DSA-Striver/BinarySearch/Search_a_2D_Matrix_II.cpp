class Solution {
public:
    int lowerbound(vector<int> &arr, int x)
    {
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = low + (high - low ) / 2;
            if(arr[mid]==x){
                return 1;
            }
            else if(arr[mid]>x){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        for(int i = 0; i<n; i++){
            int m=lowerbound(mat[i],target);
            if(m==1){
                return true;
            }
        
        }
        return false;
    }
};
