#include <cmath>
#include <string>
using namespace std;

/**
 * 想法: solution1 遞迴版
 * 時間: O(nlogn), O(n)
 */

class Solution
{
  public:
    int titleToNumber(string columnTitle)
    {
        return helper(columnTitle, 0);
    }

    int helper(string &columnTitle, int index)
    {
        if (index == columnTitle.length() - 1)
        {
            return int(columnTitle[index] - 'A' + 1);
        }
        return int(columnTitle[index] - 'A' + 1) * pow(26, columnTitle.length() - index - 1) +
               helper(columnTitle, index + 1);
    }
};