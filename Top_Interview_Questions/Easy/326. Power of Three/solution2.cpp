/**
 * 想法: solution1遞迴版
 * 時間: O(logn), 空間: O(logn)
 */

class Solution
{
  public:
    bool isPowerOfThree(int n)
    {
        if (n == 1)
        {
            return true;
        }
        else if (n < 3 || n % 3 != 0)
        {
            return false;
        }
        return isPowerOfThree(n / 3);
    }
};