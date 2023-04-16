#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 dfs+trie 來做，先將所有的字加入到 trie，再用 dfs 去走訪，如果目
 * 前節點是 endOfWord，就能確定該字存在於 board 中
 * 時間: O(k*l+m*n*4^l), k: words大小; l: 最大字串長度, m*n: board大小
 *  - k*l: 建立 trie
 *  - m*n: 跑過整個 board
 *  - 4^l: 四個方向要找，最多走 l 次
 * 空間: O(k*l)
 */

class TrieNode
{
  public:
    bool endOfWord = false;
    TrieNode *children[26];

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
  public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string &word)
    {
        TrieNode *current = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->endOfWord = true;
    }
};

class Solution
{
  public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> results;
        Trie trie;
        string path = "";
        for (int i = 0; i < words.size(); i++) // insert words into trie
        {
            trie.insert(words[i]);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, trie.root, path, results);
            }
        }
        return results;
    }

    void dfs(vector<vector<char>> &board, int row, int col, TrieNode *root, string &path, vector<string> &results)
    {
        if (root->endOfWord)
        {
            root->endOfWord = false; // change it to false to prevent it from begin found again
            results.push_back(path);
            // DO NOT RETURN HERE!!!!!! THERE MIGHT BE OTHER WORDS ALONG THIS PATH!!!!
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '*')
        {
            return;
        }
        if (root->children[board[row][col] - 'a'] != nullptr)
        {
            char temp = board[row][col];
            int index = temp - 'a'; // index of next child
            board[row][col] = '*';  // mark as visited
            path += temp;
            dfs(board, row - 1, col, root->children[index], path, results);
            dfs(board, row + 1, col, root->children[index], path, results);
            dfs(board, row, col - 1, root->children[index], path, results);
            dfs(board, row, col + 1, root->children[index], path, results);
            board[row][col] = temp;
            path.pop_back();
        }
    }
};