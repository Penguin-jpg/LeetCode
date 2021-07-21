class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /*
            參考的方法
            時間複雜度O(m)(m:bit數量)、空間複雜度O(1)
            每次都將n目前最右邊的位元丟到result，而result每次都要做左移，空出新的位置放位元

            例子:
            r:        -> 0      -> 00    -> 001  -> 0011 -> 00110 -> 0011001
            n:1001100 -> 100110 -> 10011 -> 1001 -> 100  -> 10    -> 1      -> 0
        */

        uint32_t result=0;
        
        for(int i=0;i<32;i++)
        {
            result=result<<1;
            if(n&1==1) //最右邊位元為1
            {
                result++;
            }
            n=n>>1;
        }
        
        return result;
    }
};