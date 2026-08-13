class Solution 
{
public:
    int bins(vector<int>& nums, int target, int low, int high, int index)
    {
        if(low>high)
        {
            return index;
        }
        int mid = low + ( high - low) / 2;

        if(nums[low]<=nums[mid])
        {
            if(nums[low] < target)
            {
                target = nums[low];
                index = low;
            }
            return bins(nums, target, mid+1, high, index );
        }
        else
        {
            if(nums[mid] < target)
            {
                target = nums[mid];
                index = mid;
            }
            return bins(nums, target, low, mid-1, index);
        }
    }
    int findKRotation(vector<int> &nums)
    {
        return bins(nums, INT_MAX, 0, nums.size()-1, -1);
    }

    
};
