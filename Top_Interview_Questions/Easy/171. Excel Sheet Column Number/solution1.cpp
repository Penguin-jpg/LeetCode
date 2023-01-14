#include <cmath>
#include <string>
using namespace std;

/**
 * 想法: 每多一個字串長度，就代表跑完一輪，要多乘一次 26，例如："AAB" = 26*26*1 + 26*1 + 2 = 704
 * 時間: O(nlogn), O(1)
 */

class Solution
{
  public:
    int titleToNumber(string columnTitle)
    {
        int length = columnTitle.length();
        int result = 0;
        for (int i = 0; i < columnTitle.length(); i++)
        {
            result += int(columnTitle[i] - 'A' + 1) * pow(26, length - 1);
            length--;
        }
        return result;
    }
};