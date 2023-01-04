class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            我的方法3
            時間複雜度O(n)、空間複雜度O(1)
            total記錄0+1+2+...+n，currentSum記錄nums所有內的所有數總和(不包含missing number)，
            total-currentSum則為missing number
        */

        int total=0;
        int currentSum=0;
        
        total=nums.size()*(nums.size()+1)/2;
        
        for(int i=0;i<nums.size();i++)
        {
            currentSum+=nums[i];
        }
        
        return total-currentSum;
    }
};