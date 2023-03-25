#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 由於 matrix 的每個 row 都是一個排序過的陣列，可以先將整個陣列 flatten
 * 並排序，再取第 k-1 個元素 (不符合題目要求的空間複雜度小於 O(m*n))
 * 時間: O((m*n)log(m*n)), m: row 數; n: column 數, 空間: O(m*n)
 */

class Solution
{
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        vector<int> result;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                result.push_back(matrix[i][j]);
            }
        }
        sort(result.begin(), result.end());
        return result[k - 1];
    }
};