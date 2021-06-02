class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*
            我的方法
            時間複雜度O(nlog(n))、空間複雜度O(1)
            in-place
        */

        for(int n=0;n<nums.size();n++)
        {
            nums[n]*=nums[n];
        }
        
        sort(nums.begin(),nums.end());
        
        return nums;
    }
};