#include <algorithm>
#include <set>
#include <vector>
using namespace std;

/**
 * 參考解答: 先將所有點都以 {x,h} 的形式存下來，如果是建築物的起始點，則取 -h，
 * 若是結束點則取 h，以此區分開始與結束，將 points 排序，開始 iterate points，如
 * 果遇到的 h 為負，則可知為起始點，直接加入 max-heap，若遇到為正，則從 max-heap
 * 中移除該高度，如果目前最高的高度不等於 max-heap 的 top (高度發生變化)，則代表
 * 出現需要紀錄的點，建議看原文來理解：
 * https://leetcode.com/problems/the-skyline-problem/solutions/2094329/c-easiest-explanation-ever-guaranteed-beginner-friendly-detailed-o-nlogn/
 *
 * 試著用簡單一點的方式來說：
 * 有點像是把每個建築的起點跟終點抓出來排序，而為了區分起點與終點就用高加上正負
 * 號來區分，遇到起點時，需要將高加到 fallback list，這個 list 代表的是目前所有
 * 遇到且還沒走到底的建築的高(需要 max-heap 是因為我們需要能快速的取出 list 內的
 * 最大值)，我們也同時需要紀錄目前最大的高度 ongoingHeight(必須是還沒走到底的建
 * 築，所以命名時才特別取名叫 ongoing)，當遇到起點時，就將該高度放入 list，當遇
 * 到終點時，我們就將該高度移出 list(因為該高度無法再被使用)，如果做完後，list
 * 內的最大值和 ongoingHeight 不同，代表目前遇到的點是擁有 ongoingHeight 的那棟
 * 建築無法包住的點，所以必須記錄，將這些點全部找出就是答案
 * 時間: O(nlogn), 空間: O(n)
 */

class Solution
{
  public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> results;
        // store every height we met during iterate (we should use max-heap, but c++ max-heap doesn't let you delete any
        // node you want, so we use multiset instead)
        // c++ multiset will keep numbers in increasing order
        multiset<int> fallback{0};
        // fallback.insert(0);    // prevent fallback list from empty and has someone to compare
        int ongoingHeight = 0; // max height (belongs to an ongoing building)
        vector<pair<int, int>> points;
        for (int i = 0; i < buildings.size(); i++)
        {
            points.push_back(make_pair(buildings[i][0], -buildings[i][2])); // start point
            points.push_back(make_pair(buildings[i][1], buildings[i][2]));  // end point
        }
        sort(points.begin(), points.end()); // sort according to x
        for (int i = 0; i < points.size(); i++)
        {
            if (points[i].second < 0)
            {
                fallback.insert(-points[i].second); // add to fallback if it is a start point
            }
            else
            {
                // erase it from fallback if it is an end point (since we cannot use it anymore)
                fallback.erase(fallback.find(points[i].second));
            }
            int top = *fallback.rbegin(); // multiset has max value at back
            if (ongoingHeight != top)     // if height changes
            {
                ongoingHeight = top;
                results.push_back({points[i].first, ongoingHeight});
            }
        }
        return results;
    }
};