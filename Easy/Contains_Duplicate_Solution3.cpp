class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
            參考的方法1
            時間複雜度O(nlog(n))、空間複雜度O(1)
        */

        if(nums.size()==1)
        {
            return false;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                return true;
            }
        }
        
        return false;
    }
};