#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 使用 std::reverse (c++專用)
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};