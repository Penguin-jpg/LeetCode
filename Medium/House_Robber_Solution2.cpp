class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            參考的方法2
            時間複雜度O(n)、空間複雜度O(1)
            將方法1的陣列改為三個變數
        */
        if(nums.size()==1)
        {
            return nums[0];
        }else if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        
        int temp=0;
        int prev=nums[0];
        int next=max(nums[0],nums[1]);
        
        for(int n=2;n<nums.size();n++)
        {
            temp=prev;
            prev=next;
            next=max(prev,temp+nums[n]);
        }
        
        return next;
    }
};