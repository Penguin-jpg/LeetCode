/**
 * 想法: 要找出全部的 5，可以用這種方式來想： 5=5, 10=2*5, 15=3*5, 20=4*5, 25=5*5, 30=6*5,...
 * 而我們可以用 n/5 來得到有幾個數字包含一個 5，n/25 來得到有幾個數字包含兩個
 * 5,...(之所以在計算 n 個 5 的時候不用乘以 n 是因為在他先前的 n-1 次都已經加過
 * 了 (n/5 + n/25 + ... + n/5^(n-1)))
 * 時間: O(log_5(n)), 空間: O(1)
 */

class Solution
{
  public:
    int trailingZeroes(int n)
    {
        int counter = 0;
        for (int i = 5; i <= n; i *= 5)
        {
            counter += n / i;
        }
        return counter;
    }
};