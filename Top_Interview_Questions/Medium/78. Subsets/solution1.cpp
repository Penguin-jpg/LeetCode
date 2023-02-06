#include <vector>
using namespace std;

/**
 * 想法: 用 backtracking 把所有 subset 找完
 * 時間: O(2^n), 空間: O(n)
 */

class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> results({{}});
        vector<int> subset;
        backtracking(nums, 0, subset, results);
        return results;
    }

    void backtracking(vector<int> &nums, int index, vector<int> &subset, vector<vector<int>> &results)
    {
        if (index >= nums.size())
        {
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            results.push_back(subset);
            backtracking(nums, i + 1, subset, results);
            subset.pop_back();
        }
    }
};