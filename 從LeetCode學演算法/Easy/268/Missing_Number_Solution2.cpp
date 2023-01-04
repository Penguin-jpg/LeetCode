class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            我的方法2
            時間複雜度O(n)、空間複雜度O(n)
        */

        vector<bool> exist(nums.size()+1,false);
        int missing=0;
        
        for(int i=0;i<nums.size();i++)
        {
            exist[nums[i]]=true;
        }
        
        for(int i=0;i<exist.size();i++)
        {
            if(!exist[i])
            {
                missing=i;
                break;
            }
        }
        
        return missing;
    }
};