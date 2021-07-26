class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        /*
            參考的方法3
            時間複雜度O(m)(m:right的bit數)、空間複雜度O(1)
            只需要留下n和m相同的部分，透過n&(n-1)每次去掉最後一個bit來完成
        */

        while(right>left)
        {
            right&=(right-1);
        }
        
        return right;
    }
};