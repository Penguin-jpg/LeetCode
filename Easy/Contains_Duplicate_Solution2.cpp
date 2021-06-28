class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
            我的方法2:
            時間複雜度O(n)、空間複雜度O(n)
        */

        if(nums.size()==1)
        {
            return false;
        }
        
        unordered_map<int,int> counters;
        
        for(int i=0;i<nums.size();i++)
        {
            if(counters.count(nums[i])!=0)
            {
                return true;
            }else
            {
                counters[nums[i]]++;
            }
        }
        
        return false;
    }
};