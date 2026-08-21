class Solution {
  public:
  int lowerbound(vector<int> &arr, int x){
    int low = 0, high = arr.size()-1;
    int ans= arr.size();
    while(low<=high){
        int mid = low + (high - low ) / 2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
  }   
  int rowWithMax1s(vector < vector < int >> & mat) {
    int n = mat.size();
    int ind = -1;
    int cnt_max=0;
    for(int i = 0; i<n; i++){
        int m = mat[i].size();
        int cnt_ones = m - lowerbound(mat[i],1);
        if(cnt_ones>cnt_max){
            cnt_max = cnt_ones;
            ind = i;
        }
        
    }
    return ind;
  }
};
