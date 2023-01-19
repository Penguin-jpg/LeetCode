#include <vector>
using namespace std;

/**
 * 參考解答: solution1簡化判斷，在過程中同時尋找 0 的位置
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    void moveZeroes(vector<int> &nums)
    {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
    }
};