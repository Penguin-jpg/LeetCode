#include <string>
using namespace std;

/**
 * 想法: 用 string.find 來找
 * 時間: O(n*m), 空間: O(1)
 */

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        int pos = haystack.find(needle);
        return pos == string::npos ? -1 : pos;
    }
};