#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 bucket sort，用出現的頻率來區分每個 bucket，再從頻率最高的
 * bucket 開始往回看，加入 k 個數到 results
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
        {
            table[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size() + 1); // at most frequency will be n
        for (auto &it : table)
        {
            buckets[it.second].push_back(it.first); // categorize buckets by frequency
        }
        // index represents frequency, so we start from the biggest frequency
        vector<int> results;
        for (int i = buckets.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < buckets[i].size(); j++)
            {
                results.push_back(buckets[i][j]);
                if (results.size() == k)
                {
                    return results;
                }
            }
        }
        return results;
    }
};