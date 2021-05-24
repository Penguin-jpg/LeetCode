class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(n)
            rob[n]代表偷到第n間的最大和，比較rob[n-1](不偷第n間)和rob[n-2]+nums[n](偷第n間)，
            取最大的當rob[n]
        */
        if(nums.size()==1)
        {
            return nums[0];
        }else if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }

        vector<int> rob(nums.size(),0);
        rob[0]=nums[0];
        rob[1]=max(nums[0],nums[1]);
        
        for(int n=2;n<nums.size();n++)
        {
            rob[n]=max(rob[n-1],rob[n-2]+nums[n]);
        }

        return rob[nums.size()-1];
    }
};