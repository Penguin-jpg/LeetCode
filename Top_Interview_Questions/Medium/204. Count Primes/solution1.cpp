/**
 * 想法: 檢查某數是否為質數的方式就是從檢查 2~n 中是否有它的能整除的數，如果有的
 * 話它就是質數 (TLE)
 * 時間: O(nlogn), 空間: O(1)
 */

class Solution
{
  public:
    int countPrimes(int n)
    {
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (isPrime(i))
            {
                counter++;
            }
        }
        return counter;
    }

    bool isPrime(int n)
    {
        if (n == 0 || n == 1)
        {
            return false;
        }
        for (int i = 2; i <= n / i; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};