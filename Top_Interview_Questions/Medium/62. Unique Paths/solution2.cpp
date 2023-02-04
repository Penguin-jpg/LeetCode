#include <vector>
using namespace std;

/**
 * 參考解答: 根據排列組合，這種題目的解法是 (m+n)!/m!n!，假設 m 永遠較大，將 m! 除掉化簡後
 * 可得 (m+n)*(m+n-1)*...*m/n!
 * 時間: O(m+n), 空間: O(1)
 */

class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        if (m < n) // we assume m is bigger and want to use this to do less steps
        {
            swap(m, n);
        }
        long long int result = 1;
        int j = 1;
        for (int i = m; i < m + n - 1; i++) // since we start from 0 so the max should be (m-1 + n-1)
        {
            result *= i;
            result /= j;
            j++;
        }
        return result;
    }
};