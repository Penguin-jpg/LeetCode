#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

/**
 * 想法: 透過 two pointers 從最左到最右開始檢查，每次遇到非字母或數字的字元就跳過
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
            while (left < right && !isalnum(s[left]))
            {
                left++;
            }
            while (left < right && !isalnum(s[right]))
            {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};