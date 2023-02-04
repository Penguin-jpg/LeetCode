#include <vector>
using namespace std;

/**
 * 參考解答: 先排序，並可簡單分成兩種情況：
 *          1. 無 overlapping -> 由於排序過了，其實只要確定 i 的結束點是否比 j
 *          的起始點更前面就好 -> 直接加入該 range
 *          2. 有 overlapping -> 由於 i 的起始點一定小於 j 的，所以只要檢查誰的
 *          結束點比較大就好 -> 更新目前的 range
 * 時間: O(nlogn), 空間: O(1)
 */

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> results;
        results.push_back(intervals[0]); // put the first interval in to prevent error
        for (int i = 1; i < intervals.size(); i++)
        {
            // only need to check if the end of the lastest stored interval
            // greater than the start of intervals[i]
            if (results.back()[1] >= intervals[i][0])
            {
                results.back()[1] = max(results.back()[1], intervals[i][1]); // only need to update the end point
            }
            else // range won't match so it is a new interval
            {
                results.push_back(intervals[i]);
            }
        }
        return results;
    }
};