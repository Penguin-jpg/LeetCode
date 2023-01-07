/**
 * 參考解答: 用二元搜尋法找
 * 時間: O(logn), 空間: O(1)
 */

class Solution
{
  public:
    int mySqrt(int x)
    {
        long long int start = 0, end = x, mid, result;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            else if (mid * mid < x)
            {
                start = mid + 1;
                result = mid; // use lowest "mid" value as answer
            }
            else
            {
                end = mid - 1;
            }
        }
        return result;
    }
};