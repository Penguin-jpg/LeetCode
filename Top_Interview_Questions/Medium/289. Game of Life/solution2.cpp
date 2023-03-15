#include <vector>
using namespace std;

/**
 * 想法: 為了要做到 in-place，不能額外存在一個新陣列，所以要引入新符號代表不同的含意：
 *      2: 原本是 1，下次是 0
 *      3: 原本是 0，下次是 1
 *      其餘情況不需修改
 * 檢查 live 的鄰居時也要將 2 納入考量，最後再一次更新上去
 * 時間: O(m*n), 空間: O(1)
 */

class Solution
{
  public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size(), n = board[0].size();
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
                            if (l >= 0 && l < n && (board[k][l] == 1 || board[k][l] == 2))
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
                        board[i][j] = 2;
                    }
                }
                else if (counter == 3)
                {
                    board[i][j] = 3;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 2)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 3)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
};