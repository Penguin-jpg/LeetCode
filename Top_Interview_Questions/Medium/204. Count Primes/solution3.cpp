#include <cmath>
#include <vector>
using namespace std;

/**
 * 想法: 建表找質數的時候，j 可以直接從 i*i 開始 (在需要宣告型態的語言記得要先轉
 * long long int)，且 i 的範圍和普通找質數方法一樣只需找到 sqrt(n)
 * 時間: O(nlog(logn)), 空間: O(n)
 */

class Solution
{
  public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
        {
            return 0;
        }
        int counter = 0;
        vector<bool> isPrime = buildTable(n);
        for (int i = 0; i < n; i++)
        {
            if (isPrime[i])
            {
                counter++;
            }
        }
        return counter;
    }

    vector<bool> buildTable(int n)
    {
        vector<bool> table(n, true);
        table[0] = false, table[1] = false;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (table[i]) // if i is prime, its mutiples are not prime
            {
                for (long long int j = (long long int)i * i; j < n; j += i)
                {
                    table[j] = false;
                }
            }
        }
        return table;
    }
};