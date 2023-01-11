#include <vector>
using namespace std;

/**
 * 參考解答: 預先配置空間，可以節省一點時間，且可以不考慮特例
 */

class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> rows(numRows);
        for (int i = 0; i < numRows; i++)
        {
            rows[i].resize(i + 1);       // adjust size of vector
            rows[i][0] = rows[i][i] = 1; // 1 at the left hand side and right hand side
            for (int j = 1; j < i; j++)
            {
                rows[i][j] = rows[i - 1][j - 1] + rows[i - 1][j];
            }
        }
        return rows;
    }
};