class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*
            我的方法2
            時間複雜度O(1)(bit長度固定)、空間複雜度O(1)(固定呼叫33次call stack)
            recursive
        */

        return recursive(n,1);
    }
    
    int recursive(uint32_t n,int len)
    {
        if(len>32)
        {
            return 0;
        }
        
        return (n&1)==1?1+recursive(n>>1,len+1):recursive(n>>1,len+1);
    }
};