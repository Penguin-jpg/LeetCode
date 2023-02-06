#include <cmath>
#include <vector>
using namespace std;

/**
 * 參考解答: solution2判斷優化
 * 時間: O(2^n), 空間: O(n)
 */

class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int size = 1 << nums.size();
        vector<vector<int>> results(size);
        for (int i = 0; i < size; i++)
        {
            vector<int> subset;
            int temp = i;
            for (int j = 0; j < nums.size(); j++)
            {
                if (temp & 1)
                {
                    subset.push_back(nums[j]);
                }
                temp >>= 1;
            }
            results[i] = subset;
        }
        return results;
    }
};