class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        /*
            參考的方法2
            時間複雜度O(m)(m:right的bit數)、空間複雜度O(1)
            更接近我的方法，但不是用pow，而是為左移的方式達到乘2倍的效果
        */

        int factor=1;
        
        while(left!=right)
        {
            left=left>>1;
            right=right>>1;
            factor=factor<<1;
        }
        
        return left*factor;
    }
};