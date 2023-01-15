/**
 * 想法: 用一個變數紀錄答案，一個變數紀錄要取出的 bit，跑一個 32 次的迴圈，每次
 * 都將 n 對應的 bit 擺到最後一位，並放到第二個變數，將該變數左移 32-i 位(反轉後的位置)，
 * 再 set 到第一個變數中
 * 時間: O(n), n: 型態bit數, 空間: O(1)
 */

class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0; // store result
        uint32_t temp = 0;   // store target bit
        for (int i = 0; i < 32; i++)
        {
            // "n << (32 - i) >> 31" is to shift the i-th bit to the last
            // position and left only this bit in n
            temp = n << (31 - i) >> 31;
            // shift i-th bit of n to reverse position
            temp <<= 31 - i;
            // set this bit to result
            result |= temp;
        }
        return result;
    }
};