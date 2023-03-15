#include <vector>
using namespace std;

/**
 * 想法: 由於題目敘述是要求，state 必須同時更新，然而若我們檢查完就改，會導致後
 * 續的 state 判斷錯誤，所以更新後的結果額外存起來，再更新到 board 上
 * 時間: O(m*n), 空間: O(m*n)
 */

class Solution
{
  public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> states(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int counter = 0;
                // check neighbors
                for (int k = i - 1; k <= i + 1; k++)
                {
                    if (k >= 0 && k < m)
                    {
                        for (int l = j - 1; l <= j + 1; l++)
                        {
                            if (l >= 0 && l < n && board[k][l] == 1)
                            {
                                counter++;
                            }
                        }
                    }
                }
                counter = board[i][j] == 1 ? counter - 1 : counter; // only count neighbors
                if (board[i][j] == 1)
                {
                    if (counter < 2 || counter > 3)
                    {
                        states[i][j] = 0;
                    }
                    else
                    {
                        states[i][j] = 1;
                    }
                }
                else if (counter == 3)
                {
                    states[i][j] = 1;
                }
                else
                {
                    states[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = states[i][j];
            }
        }
    }
};