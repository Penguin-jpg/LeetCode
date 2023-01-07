/**
 * 參考解答: 牛頓法求平方根(可疊代或遞迴)，算式如下：
 *          求 S 之平方根，則 x_{n+1} = 1/2 * (x_n + S / x_n)
 * 時間: O(logn), 空間: O(1) or O(logn) for recursive
 */

// 疊代
class Solution
{
  public:
    int mySqrt(int x)
    {
        long long int r = x;
        while (r * r > x)
        {
            r = (r + x / r) / 2;
        }
        return r;
    }
};

// 遞迴
class Solution
{
  public:
    int mySqrt(int x)
    {
        long long int r = x;
        return helper(x, r);
    }

    long long int helper(int x, long long int r)
    {
        if (r * r > x)
        {
            return helper(x, (r + x / r) / 2);
        }
        return r;
    }
};