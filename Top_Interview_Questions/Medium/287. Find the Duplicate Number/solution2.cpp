#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 想法: 將 nums 的值存到 hash set，再找有哪個重複 (會過，但不符合題目要求的
 * O(1) 空間複雜度)
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++)
        {
            if (set.count(nums[i]))
            {
                return nums[i];
            }
            else
            {
                set.insert(nums[i]);
            }
        }
        return nums[0];
    }
};