#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 dp memo法解，概念和 table法有點像，每次都檢查切出來的是否在
 * wordDict 裡面，再繼續從切的地方開始檢查
 * 時間: O(n^2), 空間: O(n)
 */

class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        return findWord(s, 0, wordSet, memo);
    }

    bool findWord(string &s, int start, unordered_set<string> &wordSet, unordered_map<int, bool> &memo)
    {
        if (start >= s.length())
        {
            return true;
        }
        else if (memo.count(start))
        {
            return memo[start];
        }
        for (int i = start + 1; i <= s.length(); i++)
        {
            if (wordSet.count(s.substr(start, i - start)))
            {
                if (findWord(s, i, wordSet, memo))
                {
                    memo[start] = true;
                    return memo[start];
                }
            }
        }
        memo[start] = false;
        return memo[start];
    }
};