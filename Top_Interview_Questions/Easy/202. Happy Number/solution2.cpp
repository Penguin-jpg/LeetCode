/**
 * 參考解答: 把問題想像成找出 cycle，所以可以用快慢指標來解
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    bool isHappy(int n)
    {
        int slow = getDigitSquareSum(n);
        int fast = getDigitSquareSum(getDigitSquareSum(n));
        // there are two possible ways to end loop:
        // 1. (slow == fast) and (fast or slow = 1)
        // 2. (slow == fast) and (fast and slow != 1)
        while (slow != fast)
        {
            slow = getDigitSquareSum(slow);
            fast = getDigitSquareSum(getDigitSquareSum(fast)); // fast pointer do twice
        }
        return fast == 1;
    }

    int getDigitSquareSum(int n)
    {
        int sum = 0;
        int digit = 0;
        while (n > 0)
        {
            digit = n % 10;
            n /= 10;
            sum += digit * digit;
        }
        return sum;
    }
};