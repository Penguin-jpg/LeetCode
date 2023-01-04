class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            先將非0的地方都用放到陣列前方，再將後方都改成0
        */

        int index=0;
        
        for(int n=0;n<nums.size();n++)
        {
            if(nums[n]!=0)
            {
                nums[index]=nums[n];
                index++;
            }
        }
        
        while(index<nums.size())
        {
            nums[index]=0;
            index++;
        }
    }
};