#include <climits>

/**
 * 參考解答: 加入 early stop，當目前的答案已經大於 INT_MAX 或已經小於 INT_MIN 時就不需繼續作了
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int reverse(int x)
    {
        long long int result = 0;
        while (x != 0)
        {
            result = result * 10 + x % 10;
            if (result > INT_MAX || result < INT_MIN)
            {
                return 0;
            }
            x /= 10;
        }
        return result;
    }
};