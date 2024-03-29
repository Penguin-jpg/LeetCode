class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /*
            我的方法1
            時間複雜度O(1)(bit數量固定)、空間複雜度(1)
            利用bitset轉字串後再反轉，最後轉回整數
        */

        bitset<32> bits(n);
        string reverseBits=bits.to_string();
        reverse(reverseBits.begin(),reverseBits.end());
        bitset<32> ans(reverseBits);
        return ans.to_ulong();
    }
};