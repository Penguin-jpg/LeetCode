#include <algorithm>
#include <string>
using namespace std;

/**
 * 想法: 先將 s 與 t 排序，再檢查兩者是否相同
 * 時間: O(nlogn), 空間: O(1)
 */

class Solution
{
  public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};