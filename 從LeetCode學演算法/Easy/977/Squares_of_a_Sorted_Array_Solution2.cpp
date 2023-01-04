class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(n)
            two pointers
            將左邊(負最小)與右邊(正最大)進行比較，較大的就從尾端放進新陣列
        */

        vector<int> newNums(nums.size());
        int left=0;
        int right=nums.size()-1;
        int index=0;
        
        for(int n=nums.size()-1;n>=0;n--)
        {
            if(abs(nums[left])>abs(nums[right]))
            {
                newNums[n]=nums[left]*nums[left];
                left++;
            }else
            {
                newNums[n]=nums[right]*nums[right];
                right--;
            }
        }
        
        return newNums;
    }
};