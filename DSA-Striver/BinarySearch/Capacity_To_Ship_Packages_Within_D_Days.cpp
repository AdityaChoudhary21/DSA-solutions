class Solution {
public:
    int func (vector<int>& weights, int capacity){
        int n = weights.size();
        int load = 0;
        int ndays = 1;
        for(int i = 0; i<n; i++){
            if(load + weights[i] > capacity){
                ndays++;
                load = weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return ndays;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = INT_MAX;
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        
        while(low<=high){
            int mid = low + (high - low ) / 2;
            int daysreq = func(weights, mid);

            if(daysreq<=days){
                high = mid - 1;
                ans = min(ans,mid);
            }  
            else{
                low = mid + 1;
            }
        }
        return ans;    
    }
};
