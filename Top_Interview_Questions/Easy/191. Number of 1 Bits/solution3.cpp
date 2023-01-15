/**
 * 參考解答: 只要 n > 0，就做 n &= (n-1)，概念是每次這樣做都會把最尾端的 1 給去掉，例子：
 *          step0. n = 00101100
 *          step1. n = 00101100, n-1 = 00101011, n &= (n-1) = 00101000
 *          step2. n = 00101000, n-1 = 00100111, n &= (n-1) = 00100000
 *          step3. n = 00100000, n-1 = 00011111, n &= (n-1) = 00000000
 * 時間: O(n), n: 1 bit的數量，空間: O(1)
 */

class Solution
{
  public:
    int hammingWeight(uint32_t n)
    {
        int counter = 0;
        while (n)
        {
            n &= (n - 1);
            counter++;
        }
        return counter;
    }
};