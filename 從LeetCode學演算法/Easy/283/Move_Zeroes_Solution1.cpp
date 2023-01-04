class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
            我的方法
            時間複雜度O(n)、空間複雜度O(1)
            紀錄出現的0的數量，將他們從nums移除後，重新加入到最尾端
        */

        int counter=0;
        
        for(int n=0;n<nums.size();)
        {
            if(nums[n]==0)
            {
                nums.erase(nums.begin()+n);
                counter++;
                
            }else
            {
                n++;
            }
        }
        
        for(int n=0;n<counter;n++)
        {
            nums.insert(nums.end(),0);
        }
    }
};