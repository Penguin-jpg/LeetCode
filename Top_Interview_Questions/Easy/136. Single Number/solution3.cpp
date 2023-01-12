#include <vector>
using namespace std;

/**
 * 參考解答: 透過 XOR 的特性，A ^ A ^ B = B -> 重複的數字會被消掉，最後只剩不重複的
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            result ^= nums[i];
        }
        return result;
    }
};