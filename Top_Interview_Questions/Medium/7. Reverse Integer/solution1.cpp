/**
 * 想法: 透過一個變數紀錄翻轉後的答案，每次迴圈開始都乘以 10，並在結束前加上原本
 * x 的最後一位數字，若要取負號的話最後再乘 -1
 * 時間: O(n), n: 數字長度, 空間: O(1)
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
            x /= 10;
        }
        return result < INT_MIN || result > INT_MAX ? 0 : result;
    }
};