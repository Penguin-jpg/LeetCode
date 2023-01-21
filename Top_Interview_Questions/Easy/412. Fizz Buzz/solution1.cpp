#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 照規則走，但規則 1 可以簡化成檢查是否能被 15 整除
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> results(n);
        for (int i = 1; i <= n; i++)
        {
            if (i % 15 == 0)
            {
                results[i - 1] = "FizzBuzz";
            }
            else if (i % 3 == 0)
            {
                results[i - 1] = "Fizz";
            }
            else if (i % 5 == 0)
            {
                results[i - 1] = "Buzz";
            }
            else
            {
                results[i - 1] = to_string(i);
            }
        }
        return results;
    }
};