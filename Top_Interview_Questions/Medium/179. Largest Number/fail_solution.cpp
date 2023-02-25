#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 開頭越大的數應該要在越前面，但因為數字可能很大，所以不能直接用整數型態
 * 來做，要先將所有數字都轉成字串，寫一個自訂的 cmp 函數，分成以下兩種情況討論：
 *      1. a,b 長度相同
 *          直接整串比較 -> 檢查不一樣的字元，把較大的那個排前面
 *      2. a,b 長度不同
 *          比較較長字元的結尾是否大於較短字元的開頭，這部分可以用下面的例子來理解，
 *          例如：a="54", b="5"
 *               a+b="545", b+a="554" -> 可以觀察到由於 b 的開頭會接在 a 的結尾，若 b 的開頭較
 *               大，就應該要往前搬才會有更大的數
 * (失敗：仍然有沒考慮的 case，例如 [432,43243])
 * 時間: O(nlogn), 空間: O(n)
 */

bool cmp(const string &a, const string &b)
{
    int i = 0, j = 0;
    while (i < a.length() && j < b.length())
    {
        if (a[i] != b[j])
        {
            return a[i] > b[j];
        }
        i++, j++;
    }
    if (i < a.length()) // b is shorter
    {
        // if a[-1] is bigger than b[0], put a in the front
        // else put b in the front
        // a="60", b="6" -> a[-1]='0'<b[0]='6' -> b,a
        return a[a.length() - 1] > b[0];
    }
    else // a is shorter
    {
        // if b[-1] is smaller than a[0], put a in the front
        // else put b in the front
        // a="6", b="60" -> b[-1]='0'<a[0]='6' -> a,b
        return b[b.length() - 1] < a[0];
    }
}

class Solution
{
  public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> strs(nums.size());
        string result = "";
        for (int i = 0; i < nums.size(); i++)
        {
            strs[i] = to_string(nums[i]);
        }
        sort(strs.begin(), strs.end(), cmp);
        for (int i = 0; i < strs.size(); i++)
        {
            result += strs[i];
        }
        return result;
    }
};