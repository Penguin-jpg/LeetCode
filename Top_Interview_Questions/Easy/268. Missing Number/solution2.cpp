#include <vector>
using namespace std;

/**
 * 想法: 建一個 bool 陣列，紀錄 0 ~ n 是否出現，回傳沒出現的數字
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int missingNumber(vector<int> &nums)
    {
        vector<bool> exists(nums.size() + 1, false);
        for (int i = 0; i < nums.size(); i++)
        {
            exists[nums[i]] = true;
        }
        for (int i = 0; i < nums.size() + 1; i++)
        {
            if (!exists[i])
            {
                return i;
            }
        }
        return 0;
    }
};