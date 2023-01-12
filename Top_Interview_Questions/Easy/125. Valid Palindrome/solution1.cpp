#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

/**
 * 想法: 先移除空格及標點符號，再透過 two pointers 從最左及最右開始比較
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    bool isPalindrome(string s)
    {
        // remove space and punctuation
        // (use a lambda function to decide if the char is space or punctuation)
        s.erase(remove_if(s.begin(), s.end(), [](char ch) { return isspace(ch) || ispunct(ch); }), s.end());
        int left = 0, right = s.length() - 1;
        while (left < right)
        {
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