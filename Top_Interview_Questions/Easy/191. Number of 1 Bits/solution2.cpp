/**
 * 想法: 每次都檢查最後一個 bit，如果是 1 的話，counter++
 * 時間: O(n), n: 型態bit數, 空間: O(1)
 */

class Solution
{
  public:
    int hammingWeight(uint32_t n)
    {
        int counter = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & 1)
            {
                counter++;
            }
            n >>= 1;
        }
        return counter;
    }
};