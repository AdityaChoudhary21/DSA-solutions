class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = indices.size();
        int count=0;
        vector<int> nge;
        for(int i = 0; i<n; i++){
            int idx = indices[i];
            int count=0;
            for(int j = idx+1; j<arr.size(); j++ ){
                if(arr[j]>arr[idx]){
                    count++;
                }
            }
            nge.push_back(count);
        }
        return nge;
    }
};

