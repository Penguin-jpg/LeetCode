/**
 * 想法: solution1 優化版，速度上會快一點
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int trailingZeroes(int n)
    {
        int counter = 0;
        int temp = 0;
        for (int i = 5; i <= n; i += 5)
        {
            temp = i;
            while (temp != 0 && temp % 5 == 0)
            {
                counter++;
                temp /= 5;
            }
        }
        return counter;
    }
};