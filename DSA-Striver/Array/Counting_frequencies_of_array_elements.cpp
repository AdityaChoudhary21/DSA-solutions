#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    vector<vector<int>> countfrequencies(vector<int> nums){
        map<int,int> freq;
        
        for (int i : nums){
            freq[i]++;
        }
        
        vector<vector<int>> result;
        
        for(auto p : freq){
            result.push_back({p.first,p.second});
        }
        return result;
    }
};

int main(){
    solution sol;

    vector<int> nums = {1,2,3,2,1};
    vector<vector<int>> ans = sol.countfrequencies(nums);

    for (auto pair : ans)       
    {
        cout<<pair[0]<<"-->"<<pair[1]<<endl;
    }
    
    return 0;
}