class Solution {
public:
    int bins(int n, int low, int high ){
        if(low>high){
            return high;
        }
        int mid = low + (high - low) / 2;
        if(mid*mid == n){
            return mid;
        }
        else if(mid*mid > n){
            return bins(n, low, mid-1);
        }
        else{
            return bins(n, mid+1, high);
        }
    }
    int floorSqrt(int n)  {
        return bins(n, 1, n);
    }
};
