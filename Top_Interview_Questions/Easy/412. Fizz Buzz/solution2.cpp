#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答: 直接對不同情況用四個迴圈寫 (實際上通常寫入比運算快很多，透過這樣的方式反而可能比較快)
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
            results[i - 1] = to_string(i);
        }
        // use i < n to prevent out of range
        for (int i = 2; i < n; i += 3)
        {
            results[i] = "Fizz";
        }
        for (int i = 4; i < n; i += 5)
        {
            results[i] = "Buzz";
        }
        for (int i = 14; i < n; i += 15)
        {
            results[i] = "FizzBuzz";
        }
        return results;
    }
};