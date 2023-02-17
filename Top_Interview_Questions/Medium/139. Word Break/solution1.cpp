#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 參考解答: 這一題的題目有點難懂，所以要解釋清楚一點，題目問的是能不能從字串 s
 * 中找出某些切法使切出來的子字串都在 wordDict 裡面，例如：
 *    s="apple", wordDict=["app","apple"]
 *    - 切出 app -> app/le -> le 不在 wordDict 內 -> 不行
 *    - 切出 apple -> apple/ -> apple 在 wordDcit 內 -> 可以
 *    -> return true
 * 由於這一題要暴力解的話需要 O(2^n) 來找出所有 wordDict 的取法，所以要用 dp
 * 的方式來解，dp[i] 代表 s 從 0 到第 i-1 個字元的切割是否有在 wordDict 內，從
 * i-1 開始一直到 0，去找是否能在該範圍內形成存在的 word
 * 時間: O(n^2), 空間: O(n)
 */

class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // since every word is unique, we can convert wordDict to hash set for faster loop uk
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length(), false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                // if dp[j] is false, it means that this will generate some words that are not in wordDict(wordSet)
                if (dp[j])
                {
                    // there exists a valid word in range [0, i-1]
                    if (wordSet.count(s.substr(j, i - j)))
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};