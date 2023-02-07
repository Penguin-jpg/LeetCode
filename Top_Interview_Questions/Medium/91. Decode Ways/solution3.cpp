#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答: solution2優畫版，移除了一些不必要的參數並簡化判斷
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int numDecodings(string s)
    {
        vector<int> memo(100, 0); // use index of s as key of memo
        return decode(s, 0, memo);
    }

    int decode(string &s, int index, vector<int> &memo)
    {
        if (index >= s.length())
        {
            return 1;
        }
        else if (memo[index] != 0)
        {
            return memo[index];
        }
        int result = 0;
        if (s[index] != '0') // s[index] can be a single digit
        {
            result += decode(s, index + 1, memo);
        }
        // if s[index:index+2] is in "1x~26", then it can form two digits
        if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] < '7')))
        {
            result += decode(s, index + 2, memo);
        }
        memo[index] = result;
        return memo[index];
    }
};