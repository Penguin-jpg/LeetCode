#include <vector>
using namespace std;

/**
 * 想法: 先將所有的 nums 相乘，再一個一個除取得答案，但要記得處理有 0 的例外，因
 * 為不能除以 0 (會成功，但不符合題目要求的不能用除法)
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> zeroPos;
        int product = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeroPos.push_back(i);
                if (zeroPos.size() > 1) // if there are at least two zeroes, the result is zero array
                {
                    return vector<int>(nums.size(), 0);
                }
            }
            else
            {
                product *= nums[i];
            }
        }
        vector<int> results(nums.size(), 0);
        if (zeroPos.size() == 1) // only results[i] where i is the index of the only zero is not zero
        {
            results[zeroPos[0]] = product;
            return results;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            results[i] = product / nums[i];
        }
        return results;
    }
};