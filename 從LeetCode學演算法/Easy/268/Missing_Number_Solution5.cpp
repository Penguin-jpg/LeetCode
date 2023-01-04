class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            參考的方法2
            時間複雜度O(nlog(n))、空間複雜度O(1)
            先排序，再照順序找不見的是哪個數
        */

        int missing=0;
        
        sort(nums.begin(),nums.end());
        
        //判斷邊界條件
        if(nums[nums.size()-1]!=nums.size())
        {
            return nums.size();
        }else if(nums[0]!=0)
        {
            return 0;
        }
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=i)
            {
                missing=i;
                break;
            }
        }
        
        return missing;
    }
};