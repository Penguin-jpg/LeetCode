/**
 * 想法: n<3 都不可能是 3 的指數倍 (1=3^0)，透過迴圈不斷除以 3 檢查是否整除，若
 * 到 n=1 時還沒中斷迴圈，就是 3 的指數倍
 * 時間: O(logn), 空間: O(1)
 */

class Solution
{
  public:
    bool isPowerOfThree(int n)
    {
        if (n < 3 && n != 1)
        {
            return false;
        }

        while (n != 1)
        {
            if (n % 3 != 0)
            {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};