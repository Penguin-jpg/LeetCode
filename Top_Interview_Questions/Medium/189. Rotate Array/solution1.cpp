#include <vector>
using namespace std;

/**
 * 想法: 用另一個陣列紀錄原陣列 (能過但不符合題目要的 in-place)
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> original = nums;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[(i + k) % nums.size()] = original[i];
        }
    }
};