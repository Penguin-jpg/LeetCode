class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /*
            我的方法2
            時間複雜度O(1)(bit數量固定)、空間複雜度(1)
            利用bitset，看第i個和第(31-i)個bit分別是0還是1，然後交換兩者
        */

        bitset<32> bits(n);
        
        for(int i=0;i<16;i++)
        {
            bool test1=bits.test(i); //true的話代表bits[i]為1；false則代表為0
            bool test2=bits.test(31-i);
            
            if(test1)
            {
                bits[31-i]=1;
            }else
            {
                bits[31-i]=0;
            }
            
            if(test2)
            {
                bits[i]=1;
            }else
            {
                bits[i]=0;
            }
        }
        
        return bits.to_ulong();
    }
};