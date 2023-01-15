#include <bitset>
#include <string>
using namespace std;

/**
 * 想法: 用 bitset 轉字串，再反轉回來 (C++ 才能用)
 * 時間: O(n), n: 型態bit數, 空間: O(n)
 */

class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {
        bitset<32> original(n);
        string bitString = original.to_string();
        for (int i = 0; i < 16; i++)
        {
            swap(bitString[i], bitString[31 - i]);
        }
        bitset<32> reversed(bitString);
        return reversed.to_ulong();
    }
};