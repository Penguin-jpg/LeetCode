#include <vector>
using namespace std;

/**
 * 想法: 按照帕斯卡三角形的規則來做，將 numRows=1 當做例外，其餘則是開頭為 1 ，
 * 自己=左上+右上，尾巴補 1
 * 時間: O(n^2), 空間: O(n^2)
 */

class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 1)
        {
            return {{1}};
        }
        vector<vector<int>> results({{1}});

        for (int i = 1; i < numRows; i++)
        {
            vector<int> row({1}); // 1 at the left hand side
            for (int j = 1; j < results[i - 1].size(); j++)
            {
                row.push_back(results[i - 1][j - 1] + results[i - 1][j]);
            }
            row.push_back(1); // 1 at the right hand side
            results.push_back(row);
        }
        return results;
    }
};