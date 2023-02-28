#include <vector>
using namespace std;

/**
 * 想法: 先建立質數表(O(nlogn))，之後直接查表(O(1))即可知道是否為質數
 * 時間: O(nlogn), 空間: O(n)
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
        for (int i = 2; i < n; i++)
        {
            if (table[i]) // if i is prime, its mutiples are not prime
            {
                for (int j = i + i; j < n; j += i)
                {
                    table[j] = false;
                }
            }
        }
        return table;
    }
};