#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 參考解答: 由於 nums 中只有一個數不重複，所以整個陣列的和應為所有 unique 元素
 * 之和的兩倍加上只出現一次的數
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        unordered_set<int> set(nums.begin(), nums.end());
        int totalSum = 0;  // sum of array
        int uniqueSum = 0; // sum of unique elements
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }
        for (auto &num : set)
        {
            uniqueSum += num;
        }
        // totalSum = 2*(a1+a2+a3+...)+ak
        // uniqueSum = a1+a2+a3+...+ak
        // the difference of totalSum and 2*uniqueSum = -ak
        return (totalSum - 2 * uniqueSum) * -1;
    }
};