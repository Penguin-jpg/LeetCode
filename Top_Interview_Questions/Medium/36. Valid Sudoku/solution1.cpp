#include <vector>
using namespace std;

/**
 * 想法: 注意題目要只要求是否有照規則，不需真的把數獨解出來
 * 時間: O(n^2), 空間: O(n)
 */

class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (!checkRow(board, i))
            {
                return false;
            }
            for (int j = 0; j < 9; j++)
            {
                if (!checkCol(board, j) || !checkGrid(board, i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkRow(vector<vector<char>> &board, int row)
    {
        vector<int> exists(10, 0);
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] != '.')
            {
                exists[board[row][i] - '0']++;
            }
        }
        for (int i = 1; i <= 9; i++)
        {
            if (exists[i] > 1)
            {
                return false;
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char>> &board, int col)
    {
        vector<int> exists(10, 0);
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] != '.')
            {
                exists[board[i][col] - '0']++;
            }
        }
        for (int i = 1; i <= 9; i++)
        {
            if (exists[i] > 1)
            {
                return false;
            }
        }
        return true;
    }

    bool checkGrid(vector<vector<char>> &board, int row, int col)
    {
        int gridRow = (row / 3) * 3;
        int gridCol = (col / 3) * 3;
        vector<int> exists(10. 0);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[gridRow + i][gridCol + j] != '.')
                {
                    exists[board[gridRow + i][gridCol + j] - '0']++;
                }
            }
        }
        for (int i = 1; i <= 9; i++)
        {
            if (exists[i] > 1)
            {
                return false;
            }
        }
        return true;
    }
};