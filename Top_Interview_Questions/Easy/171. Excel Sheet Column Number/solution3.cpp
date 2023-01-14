#include <string>
using namespace std;

/**
 * 參考解答: solution1 的改良版，將 26 提出去同乘，可將時間複雜度減少到 O(n)
 * 時間: O(n), O(1)
 */

class Solution
{
  public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;
        for (int i = 0; i < columnTitle.length(); i++)
        {
            result = result * 26 + int(columnTitle[i] - 'A' + 1);
        }
        return result;
    }
};