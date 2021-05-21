class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
            參考的方法2
            時間複雜度O(n)、時間複雜度O(1)
            紀錄遇到0的位置，當遇到非0值時，就和該位置交換
        */

        int index=0;
        
        for(int n=0;n<nums.size();n++)
        {
            if(nums[n]!=0)
            {
                swap(nums[n],nums[index]);
                index++;
            }
        }
    }
};