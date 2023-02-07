#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 DFS 和 backtracking，但重點是不能只侷限於"一個起始點"(例如說都從
 * 0,0 開始走)，應該要嘗試每一個 i,j 當起始點下去走的情況
 * 時間: O(m*n), 空間: O(k), k: word長度
 */

class Solution
{
  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        // the reason why I fail is because I didn't try to use every i,j as
        // start point which leads to some cases fail
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (wordSearch(board, word, 0, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool wordSearch(vector<vector<char>> &board, string &word, int index, int row, int col)
    {
        if (index >= word.length())
        {
            return true;
        }
        // all fail conditions
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index])
        {
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '*'; // to save space, we change board[row][col] to '*' means it is visited
        bool found =
            wordSearch(board, word, index + 1, row - 1, col) || wordSearch(board, word, index + 1, row, col - 1) ||
            wordSearch(board, word, index + 1, row + 1, col) || wordSearch(board, word, index + 1, row, col + 1);
        board[row][col] = temp; // backtracking
        return found;
    }
};