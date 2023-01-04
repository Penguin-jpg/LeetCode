class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(n)
            利用hash map儲存nums[i]目前最新出現的index，當遇到新的nums[i]時，就比較有沒有符合題目要求
        */

        if(nums.size()==1)
        {
            return false;
        }
        
        unordered_map<int,int> indices;
        
        for(int i=0;i<nums.size();i++)
        {
            if(indices.count(nums[i]))
            {
                if(i-indices[nums[i]]<=k)
                {
                    return true;
                }
            }

            indices[nums[i]]=i;
        }
        
        return false;
    }
};