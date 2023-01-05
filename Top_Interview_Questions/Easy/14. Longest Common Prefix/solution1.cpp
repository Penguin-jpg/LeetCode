#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 每個字串從頭開始比較，若一樣就將該字元當作 common prefix，若不同則停
 * 止，回傳目前的 common prefix
 * 時間: O(n*m) n: 字串數量; m: 最長的字串長度, 空間: O(m)
 */

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j - 1].length() || i >= strs[j].length() || strs[j - 1][i] != strs[j][i])
                {
                    return prefix;
                }
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};