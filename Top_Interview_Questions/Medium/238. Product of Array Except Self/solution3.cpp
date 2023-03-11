#include <vector>
using namespace std;

/**
 * 參考解答: 直接對 results 做計算，先將 prefix 儲存在 results 內，再用一個額外
 * 變數 suffixProduct 從 nums[n] 開始往前乘，並將兩者相乘來達到 solution2 的效果
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> results(nums.size(), 1);
        // work just like suffix array in solution2, but we only store nums[j]*nums[j+1]*...*nums[i-1] for j<i)
        int suffixProduct = 1;
        // first, we use results to store prefix, but this time we only store
        // product of nums[j] for j<i
        for (int i = 1; i < nums.size(); i++)
        {
            results[i] = nums[i - 1] * results[i - 1];
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            // second, we calculate suffix as we calculate the answer
            results[i] *= suffixProduct; // by this we can get nums[0]*nums[1]*...*nums[i-1]*nums[i+1]*...*nums[n]
            suffixProduct *= nums[i];
        }
        return results;
    }
};