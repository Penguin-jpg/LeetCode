#include <vector>
using namespace std;

/**
 * 想法: 透過一個變數 pos 紀錄要交換的位置，若目前 pos=-1(未找到交換位置)且目前
 * 位置是 0，則更新 pos，若 pos!=-1 且 nums[i]!=0，就將 nums[i] 與 nums[pos] 交
 * 換，此時可能有兩種情況：
 *      1. pos 後面不為 0，例如: 1,0,12,5
 *      2. pos 後面為 0，例如: 1,0,0,12,5
 * 兩種情況都能在交換後透過 pos++ 解決
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    void moveZeroes(vector<int> &nums)
    {
        int pos = -1; // position of zero
        for (int i = 0; i < nums.size(); i++)
        {
            if (pos == -1 && nums[i] == 0)
            {
                pos = i;
            }
            else if (pos != -1 && nums[i] != 0)
            {
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
    }
};