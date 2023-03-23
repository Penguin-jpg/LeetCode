#include <algortihm>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 想法: 先透過 hash map 存出現頻率，再換到陣列排序(將頻率大的擺前面)，最後將前
 * k 個放到 results
 * 時間: O(nlogn), 空間: O(n)
 */

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second; // move the one with higher frequency to front
}

class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> results(k);
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
        {
            table[nums[i]]++; // count frequency
        }
        vector<pair<int, int>> temp(table.begin(), table.end());
        sort(temp.begin(), temp.end(), cmp); // sort by frequency
        for (int i = 0; i < k; i++)
        {
            results[i] = temp[i].first; // store results
        }
        return results;
    }
};