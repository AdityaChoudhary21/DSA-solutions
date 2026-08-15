class Solution {
public:
    long long func(vector<int>& piles, int hourly){
        long long totalhrs=0;
        int n = piles.size();
        for(int i=0; i<n; i++){
            totalhrs+=ceil((double)piles[i]/(double)hourly);
        }
        return totalhrs;
    }
    int bins(vector<int>& piles, int low, int high, int h, int ans ){
        if(low>high){
            return low;
        }
        int mid = low + (high - low) / 2;
        long long totalhrs=func(piles,mid);

        if(totalhrs<=h){
            return bins(piles, low, mid-1, h, ans=min(ans,mid));
        }
        else{
            return bins(piles, mid+1, high, h, ans);
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_piles = *max_element(piles.begin(), piles.end());
        return bins(piles, 1, max_piles, h, INT_MAX);
        
    }
};
