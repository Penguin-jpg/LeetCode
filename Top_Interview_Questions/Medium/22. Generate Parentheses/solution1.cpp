#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答: 調整原本 backtracking 迴圈的概念，改用兩個計數器分別記錄還需要幾個
 * 左括號以及右括號，並依序補上(可以省掉檢查是否合格)
 * 時間: O(2^n), 空間: O(n)
 */

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> results;
        generate(results, "", n, n);
        return results;
    }

    void generate(vector<string> &results, string parentheis, int left, int right)
    {
        if (left == 0 && right == 0) // use all left and right parenthesis
        {
            results.push_back(parentheis);
            return;
        }
        if (left > 0)
        {
            generate(results, parentheis + '(', left - 1, right);
        }
        if (right > left) // only place right parenthesis when there is a left parenthesis
        {
            generate(results, parentheis + ')', left, right - 1);
        }
    }
};