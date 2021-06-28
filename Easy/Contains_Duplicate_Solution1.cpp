class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
            我的方法1
            時間複雜度O(n)、空間複雜度O(n)
        */

        if(nums.size()==1)
        {
            return false;
        }
        
        unordered_map<int,int> counters;
        
        for(int i=0;i<nums.size();i++)
        {
            counters[nums[i]]++;
            if(counters[nums[i]]>=2)
            {
                return true;
            }
        }
        
        return false;
    }
};