#include <bitset>
using namespace std;

/**
 * 想法: 用 bitset 來算(C++ 專用)
 * 時間: O(n), n: 型態bit數, 空間: O(n)
 */

class Solution
{
  public:
    int hammingWeight(uint32_t n)
    {
        bitset<32> bits(n);
        return bits.count();
    }
};