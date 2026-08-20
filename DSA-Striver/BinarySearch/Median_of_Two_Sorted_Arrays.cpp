class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int cnt =0;
        int n =(nums1.size()+nums2.size());
        int i = 0, j = 0;
        int median2 = n/2;
        int median1 = (n/2)-1;
        int indel1=-1, indel2=-1;

        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j]){
                if(cnt==median1) indel1=nums1[i];
                if(cnt==median2) indel2=nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt==median1) indel1=nums2[j];
                if(cnt==median2) indel2=nums2[j];
                cnt++;
                j++;
            }
            
        }

        while(i<nums1.size()){
            if(cnt==median1) indel1=nums1[i];
            if(cnt==median2) indel2=nums1[i];
            cnt++;
            i++;
        }

        while(j<nums2.size()){
            if(cnt==median1) indel1=nums2[j];
            if(cnt==median2) indel2=nums2[j];
            cnt++;
            j++;
        }

        if(n%2==1){
            return indel2;
        }
        return (double)((double)(indel1 +indel2)) / 2.0;
 
    }
};
