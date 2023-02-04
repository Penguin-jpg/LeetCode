#include <vector>
using namespace std;

/**
 * 想法: 暴力解，先排序，確定起始點由小到大排完，才能保證後續會對，從 i 開始，檢
 * 查每種重疊的情況，如果重疊，就檢查需不需要更新 interval，並將該 index 紀錄，
 * 之後就不會再拿重複的 interval 做合併
 * 時間: O(n^2), 空間: O(n)
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
        vector<bool> merged(intervals.size(), false);
        vector<vector<int>> results;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (!merged[i])
            {
                merged[i] = true;
                vector<int> interval({intervals[i][0], intervals[i][1]});
                for (int j = i + 1; j < intervals.size(); j++)
                {
                    if (!merged[j])
                    {
                        // three cases of overlapping:
                        // 1. overlap at left
                        // 2. overlap at right
                        // 3. one contains the other
                        // two cases of not overlapping (we will check this):
                        // 1. intervals[j][1] < interval[0] (don't need to worry
                        //    because already sorted)
                        // 2. intervals[j][0] > interval[1]
                        if (!(intervals[j][0] > interval[1]))
                        {
                            merged[j] = true;
                            // no need to check left range since already sorted
                            interval[1] = max(interval[1], intervals[j][1]);
                        }
                    }
                }
                results.push_back(interval);
            }
        }
        return results;
    }
};