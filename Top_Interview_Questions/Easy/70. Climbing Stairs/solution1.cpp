/**
 * 想法: 透過遞迴的方式來看，可以察覺 climbStairs(n) = climbStairs(n-1) +
 * climbStairs(n-2)，透過該規律計算並存到陣列即可 (DP表格法)
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return n;
        }
        int results[n + 1];
        results[1] = 1;
        results[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            results[i] = results[i - 1] + results[i - 2];
        }
        return results[n];
    }
};