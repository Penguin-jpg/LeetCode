#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

/**
 * 參考解答: solution2 的優化版本，移除多餘的 while 迴圈
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;
        while (left < right)
        {
            if (!isalnum(s[left]))
            {
                left++;
            }
            else if (!isalnum(s[right]))
            {
                right--;
            }
            else if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};