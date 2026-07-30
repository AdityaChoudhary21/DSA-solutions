#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& nums, int n) {
    
    int temp=nums[0];
    for(int i=0; i<n-1; i++)
    {
        nums[i]=nums[i+1];
    }
    nums[n-1]=temp;
    return nums;
}
