#include <vector>
using namespace std;

/**
 * 參考解答: 只要把不是 0 的數字都先搬到前面，並同時記錄從哪邊開始應該要是 0，把後面全部變成 0 就好
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
                nums[pos] = nums[i];
                pos++;
            }
        }
        for (int i = pos; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};