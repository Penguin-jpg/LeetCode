#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 min-heap 來做，並將 heap 大小維持在 k，當 heap 建完後，將值全部
 * 取出即為答案
 * (c++ 的 heap 是實作成 priority_queue)
 * 時間: O(nlogk), 空間: O(n)
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
        // this line means build a priority queue on vector using the rule std::greater
        // first: frequency, second: corresponding number
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> minHeap;
        for (auto &it : table)
        {
            minHeap.push(make_pair(it.second, it.first));
            // we can safely keep the size at k because we what we pop is the
            // min value which does not affect answer
            if (minHeap.size() > k) // we only need top k
            {
                minHeap.pop();
            }
        }
        vector<int> results;
        while (!minHeap.empty())
        {
            results.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return results;
    }
};