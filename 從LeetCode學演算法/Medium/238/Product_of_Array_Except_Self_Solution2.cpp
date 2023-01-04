class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*  
            參考的方法
            時間複雜度O(n)、空間複雜度O(1)(題目說回傳的vector不算入空間複雜度)
            將整個乘法拆成兩半，先算從左邊乘過來的，再乘上從右邊乘過來的

            示意圖:
            nums    2		3		4		5
            所求    3*4*5   2*4*5   2*3*5   2*3*4    ->將left*right即為所求
            left	1       2		2*3	    2*3*4
            right	3*4*5	4*5		5		1
        */

        vector<int> products(nums.size());
        products[0]=1;
        int right=1;
        
        //從左邊算
        for(int n=1;n<nums.size();n++)
        {
            products[n]=products[n-1]*nums[n-1];
        }
        
        //從右邊算
        for(int n=nums.size()-1;n>=0;n--)
        {
            products[n]*=right;
            right*=nums[n];
        }
        
        return products;
    }
};