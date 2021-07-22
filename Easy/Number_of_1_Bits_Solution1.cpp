class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*
            我的方法1
            時間複雜度O(1)(bit長度固定)、空間複雜度O(1)
            iterative
        */

        int counter=0;
        
        for(int i=0;i<32;i++)
        {
            if(n&1==1)
            {
                counter++;
            }
            n=n>>1;
        }
        
        return counter;
    }
};