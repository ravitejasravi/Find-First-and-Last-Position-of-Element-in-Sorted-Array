class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int result_index=-1, large_index=-1, small_index=-1;
        
        int low = 0, high = nums.size() - 1, mid =0;
        
        if(nums.size() < 1)
            return {-1, -1};
        
        else if(nums.size() == 1)
        {
            if(target == nums[0])
                return {0, 0};
            
            else
                return {-1, -1};
        }
        
        while(low <= high)
        {
            mid = (low+high)/2;
            
            if(target == nums[mid])
            {
                result_index = mid;
                break;
            }
            
            if(target < nums[mid])
                high = mid -1;
            else
                low = mid + 1;
        }
        
        if(result_index == -1)
            return {-1, -1};
        
        small_index = result_index;
        large_index = result_index;
        
        if(result_index != 0)
        {
            for(int i = mid - 1; i >= 0; i--)
            {
                if(nums[mid] == nums[i])
                {
                    small_index = i;
                }
                else
                    break;
            }
        }
        
        if(result_index != (nums.size() - 1))
        {
            
            for(int i = mid + 1; i < nums.size(); i++)
            {
                if(nums[mid] == nums[i])
                {
                    large_index = i;
                }
                else
                    break;
            }
        }
        
        return {small_index, large_index};
        
    }
};