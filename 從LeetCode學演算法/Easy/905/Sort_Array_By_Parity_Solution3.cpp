class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        /*
            我的方法3
            時間複雜度O(n)、空間複雜度O(1)
            紀錄上一次奇數的位置，如果遇到偶數就做交換
        */

        if(nums.size()==1)
        {
            return nums;
        }
        
        int lastOddPos=0;
        
        for(int n=0;n<nums.size();n++)
        {
            if(nums[lastOddPos]%2==0)
            {
                lastOddPos++;
            }else if(nums[n]%2==0)
            {
                swap(nums[lastOddPos],nums[n]);
                lastOddPos++;
            }
        }
        
        return nums;
    }
};