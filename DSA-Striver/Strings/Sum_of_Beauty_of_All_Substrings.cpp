class Solution {
public:
    int beautySum(string s) {
        int totalbeauty = 0;

        for(int i = 0; i < s.length(); i++){
            vector<int> freq(26,0);
            for(int j = i; j < s.length(); j++){
                freq[s[j] -'a']++;

                int maxfreq = 0;
                int minfreq = INT_MAX;
                for(int k = 0; k< 26; k++){
                    if(freq[k]>0)
                    {
                        maxfreq = max(maxfreq, freq[k]);
                        minfreq = min(minfreq, freq[k]);
                    }
                }
                totalbeauty += (maxfreq - minfreq);
            }
        }
        return totalbeauty;
        
    }
};


