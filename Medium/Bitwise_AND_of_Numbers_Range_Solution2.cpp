class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        /*
            參考的方法1
            時間複雜度O(m)(m:right的bit數)、空間複雜度O(1)
            類似我的方法，但用了更聰明的方式解決，只要找到left和right完全相同的bit區域，
            並在後方補零即為答案
        */

        int factor=0;
        
        while(left!=right)
        {
            left=left>>1;
            right=right>>1;
            factor++;
        }
        
        return left<<factor;
    }
};