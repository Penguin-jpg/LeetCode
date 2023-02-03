#include <vector>
using namespace std;

/**
 * 參考解答: 用 greedy 解，每次都跳目前的最大值
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int furthest = 0; // the furthest distance we jump so far
        for (int i = 0; i < nums.size(); i++)
        {
            if (furthest < i) // cannot even reach index i
            {
                return false;
            }
            furthest = max(i + nums[i], furthest); // check if jump from i is further than current furthest
        }
        return true;
    }
};