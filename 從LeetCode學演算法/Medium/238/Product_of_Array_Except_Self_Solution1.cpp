class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            我的方法(但題目其實不希望我們用除法)
            時間複雜度O(n)、空間複雜度O(1)
            將總乘積算出，並在第i個時除以nums[i]，
            例外狀況是有0的時候，在這個0所在位置i以外的所有數乘積都為0，
            但這個0會擁有0~i-1的乘積
        */

        vector<int> products(nums.size(),0);
        int product=1;
        int zeroPos=-1;
        
        for(int n=0;n<nums.size();n++)
        {
            if(nums[n]==0&&zeroPos==-1)
            {
                zeroPos=n;
            }else
            {
                product*=nums[n];
            }   
        }
        
        if(zeroPos!=-1)
        {
            products[zeroPos]=product;
        }else
        {
            for(int n=0;n<nums.size();n++)
            {
                products[n]=product/nums[n];
            }
        }
        
        return products;
    }
};