#include <cmath>

/**
 * 想法:: 用 C++ 的 sqrt 來做
 * 時間: O(logn), 空間: O(1)
 */

class Solution
{
  public:
    int mySqrt(int x)
    {
        return int(sqrt(x));
    }
};