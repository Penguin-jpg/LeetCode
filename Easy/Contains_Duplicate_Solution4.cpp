class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
            參考的方法2
            時間複雜度O(n)、空間複雜度O(n)
        */

        if(nums.size()==1)   
        {
            return false;
        }
        
        unordered_set<int> temp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(temp.find(nums[i])!=temp.end())
            {
                return true;
            }else
            {
                temp.insert(nums[i]);
            }
        }
        
        return false;
    }
};