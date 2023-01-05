#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答: 因為最長的 common prefix 只有可能是最短的字串，所以先排序，再檢查最
 * 短的字串與最長字串的 common prefix 即可
 * 時間: O(nlogn*m) n: 字串數量; m: 最長的字串長度, 空間: O(m)
 */

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        int last = strs.size() - 1;
        sort(strs.begin(), strs.end());
        for (int i = 0; i < strs[0].length(); i++)
        {
            if (strs[0][i] == strs[last][i])
            {
                prefix += strs[0][i];
            }
            else
            {
                break;
            }
        }
        return prefix;
    }
};