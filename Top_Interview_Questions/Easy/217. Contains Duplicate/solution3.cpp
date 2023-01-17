#include <unordered_set>
using namespace std;

/**
 * 參考解答: 先將 nums 存到一個 set 裡，如果 nums 的大小比 set 還大，就代表有重
 * 複數字，回傳 true
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        return nums.size() > uniqueNums.size();
    }
};