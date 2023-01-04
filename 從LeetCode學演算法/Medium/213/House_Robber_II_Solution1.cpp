class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            因為變成環狀，所以要考慮兩種情況
            1. 偷第一間房子 -> 不能偷最後一間
            2. 不偷第一間房子 -> 可以偷最後一間
            算出兩種情況再比較誰比較大
        */

        if(nums.size()==1)
        {
            return nums[0];
        }else if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        
        int temp=0;
        int result=0;
        int prev=nums[0];
        int next=nums[0];
        
        for(int n=2;n<nums.size()-1;n++)
        {
            temp=prev;
            prev=next;
            next=max(prev,temp+nums[n]);
        }
        
        result=next;
        
        prev=0;
        next=nums[1];
        
        for(int n=2;n<nums.size();n++)
        {
            temp=prev;
            prev=next;
            next=max(prev,temp+nums[n]);
        }
        
        return max(result,next);
    }
};