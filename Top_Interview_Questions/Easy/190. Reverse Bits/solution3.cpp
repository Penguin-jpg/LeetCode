/**
 * 參考解答: 其實只要和 1 取 AND 就能得到最後一個 bit，可以將 solution1 簡化
 * 時間: O(n), n: 型態bit數, 空間: O(1)
 */

class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++)
        {
            result = (result << 1) | (n >> i & 1);
        }
        return result;
    }
};