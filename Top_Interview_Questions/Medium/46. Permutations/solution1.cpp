#include <vector>
using namespace std;

/**
 * 參考解答: 用 backtracking 找出所有排列
 * 時間: O(n!), 空間: (n!)
 */

class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> results;
        findPermutations(nums, 0, results);
        return results;
    }

    void findPermutations(vector<int> &nums, int index, vector<vector<int>> &results)
    {
        if (index >= nums.size())
        {
            results.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            findPermutations(nums, index + 1, results);
            swap(nums[i], nums[index]);
        }
    }
};