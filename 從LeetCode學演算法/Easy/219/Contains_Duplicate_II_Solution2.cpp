class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*
            參考的方法2
            時間複雜度O(n)、空間複雜度O(n)
        */

        if(nums.size()==1)
        {
            return false;
        }
        
        unordered_map<int,vector<int>> indices;
        
        for(int i=0;i<nums.size();i++)
        {
            if(indices[nums[i]].empty())
            {
                indices[nums[i]].push_back(i);
                continue;
            }
            
            if(i-indices[nums[i]].back()<=k)
            {
                return true;
            }
            
            indices[nums[i]].push_back(i);
        }
        
        return false;
    }
};