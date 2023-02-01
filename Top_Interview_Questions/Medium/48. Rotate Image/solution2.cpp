#include <algorithm>
#include <vector>
using namespace std;

/**
 * 參考解答: 目標是將 i,j 轉換到 j, n-i-1，要轉 90 度只需要先做轉置，再將每
 * 個 row 順序 reverse 就好
 *      1. 轉置 (i,j -> j,i)
 *          1 2 3       1 4 7
 *          4 5 6  ->   2 5 8
 *          7 8 9       3 6 9
 *      2. 將每個 row 順序 reverse (j,i -> j, n-i-1，應該可以看出來這個是在做 reverse)
 *          1 4 7       7 4 1
 *          2 5 8  ->   8 5 2
 *          3 6 9       9 6 3
 * 時間: O(n^2), 空間: O(1)
 */

class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++) // stop at i or we will end up swap ji back to ij
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};