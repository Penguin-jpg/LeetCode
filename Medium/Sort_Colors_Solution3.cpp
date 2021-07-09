class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            參考的方法2
            時間複雜度O(n)、空間複雜度O(1)
            用i0紀錄0的位置，i2紀錄2的位置，當遇到0時，就和i0交換位置，
            當遇到2時，就和i2交換位置，但因為2換完後會影響順序，所以要i--，重新檢查第i個位置
        */

        int i0=0;
        int i2=nums.size()-1;
        
        for(int i=0;i<=i2;i++)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[i0]);
                i0++;
            }else if(nums[i]==2)
            {
                swap(nums[i],nums[i2]);
                i2--;
                i--;
            }
        }
    }
};