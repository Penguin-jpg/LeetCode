class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        /*  
            我的方法1
            時間複雜度O(n)、空間複雜度O(n)
            先將偶數放數新陣列，再將奇數放入新陣列
        */

        if(nums.size()==1)
        {
            return nums;
        }
        
        int index=0;
        vector<int> newNums(nums.size());
        
        for(int n=0;n<nums.size();n++)
        {
            if(nums[n]%2==0)
            {
                newNums[index]=nums[n];
                index++;
            }
        }
        
        for(int n=0;n<nums.size();n++)
        {
            if(nums[n]%2!=0)
            {
                newNums[index]=nums[n];
                index++;
            }
        }
        
        return newNums;
    }
};