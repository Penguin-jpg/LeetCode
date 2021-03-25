class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
            我的方法
            複雜度為O(n^2)
        */
        vector<int> indices;
        int len=nums.size();
        
        //預留空間
        indices.reserve(2);
        
        //尋訪整個vector
        for(int i=0;i<len;i++)
        {
            //如果找的到數字相加後等於target，就輸出解答
            for(int j=i+1;j<len;j++)
            {
                if(target-nums[i]==nums[j])
                {
                    indices.emplace_back(i);
                    indices.emplace_back(j);
                    break;
                }
            }
        }
        
        return indices;
    }
};