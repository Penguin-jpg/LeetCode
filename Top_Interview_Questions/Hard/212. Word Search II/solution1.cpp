#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 用 dfs 做，將所有可能找出 (TLE)
 * 時間: O(m*n*k), m*n: board大小; k: words數量, 空間: O(k)
 */

class Solution
{
  public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int m = board.size(), n = board[0].size();
        vector<string> results;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < words.size(); k++)
                {
                    if (words[k] != "" && m * n >= words[k].length() && dfs(board, i, j, words[k], 0, m, n))
                    {
                        results.push_back(words[k]);
                        // mark as the word as found
                        words[k] = "";
                    }
                }
            }
        }
        return results;
    }

    bool dfs(vector<vector<char>> &board, int row, int col, string &word, int index, int m, int n)
    {
        if (index >= word.length())
        {
            return true;
        }
        else if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[index])
        {
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '*'; // mark as visited
        bool found = dfs(board, row - 1, col, word, index + 1, m, n) ||
                     dfs(board, row + 1, col, word, index + 1, m, n) ||
                     dfs(board, row, col - 1, word, index + 1, m, n) || dfs(board, row, col + 1, word, index + 1, m, n);
        board[row][col] = temp;
        return found;
    }
};