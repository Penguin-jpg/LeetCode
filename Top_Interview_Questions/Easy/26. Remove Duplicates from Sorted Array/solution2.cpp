#include <vector>
using namespace std;

/**
 * 參考解答: 換個角度想，其實最後 pos 是多少就代表有幾個 unique 元素，因為每遇到
 * 一個 unique 元素需要交換一次，且由於題目說了是 non-decreasing order，所以只要前後
 * 比較就好(但就不能用 swap，不然判斷會出錯)
 */

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int pos = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[pos] = nums[i];
                pos++;
            }
        }
        return pos;
    }
};