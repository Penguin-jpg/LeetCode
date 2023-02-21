#include <vector>
using namespace std;

/**
 * 想法: 分成奇數個負數與偶數個負數來討論：
 *      1. 偶數個負數：把整個 nums 都乘起來就是答案
 *      2. 奇數個負數：設有 n 個負數，討論 n-1 個(偶數個)負數的組合
 *         例如：[3,-2,4,-5,-10]
 *          -> -2,-5,-10 三個負數 -> 討論 2 個負數的情況
 *          -> (-2,-5): 3*-2*4*-5=120
 *          -> (-5,-10): 4*-5*-10=200
 *          -> 組合 2 有最大乘積
 * (失敗，忘記考慮 nums 會有 0 存在)
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        int product = 1, maxProduct = INT_MIN;
        vector<int> negativePos;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                negativePos.push_back(i);
            }
            product *= nums[i];
        }
        if (negativePos.size() % 2 == 0)
        {
            return product;
        }
        int numNegative = negativePos.size();
        int start = -1;
        for (int i = 0; i + numNegative - 1 <= numNegative; i++)
        {
            product = 1;
            int end = i + numNegative - 1 < numNegative ? negativePos[i + numNegative - 1] : nums.size();
            for (int j = start + 1; j < end; j++)
            {
                product *= nums[j];
            }
            maxProduct = max(maxProduct, product);
            start = negativePos[i];
        }
        return maxProduct;
    }
};