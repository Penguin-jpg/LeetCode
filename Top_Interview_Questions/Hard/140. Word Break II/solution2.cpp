#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 dp memo 法來解，利用 wordDict 的資訊，我們首先檢查目前的 s 及其子字串是否
 * 是某個 wordDict 內的 word，如果是，則若答案存在的話，該 word 必為其中一部分，接下
 * 來就從 s 中去掉該 word 後的子字串繼續往下找所有組合，最後找到的結果全部合起來就是答案
 * memo 則可以將過程中 word 產生的對應的陣列儲存起來，以避免重複計算
 * (由於找 sub 時是取 [i:]，所以 remain 就要取 [:i])
 * 時間: 不知道, 空間: 不知道
 */

class Solution
{
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return dfs(s, words, memo);
    }

    vector<string> dfs(string s, unordered_set<string> &words, unordered_map<string, vector<string>> &memo)
    {
        if (memo.count(s))
        {
            return memo[s];
        }
        vector<string> results;
        if (words.count(s)) // s is the word and cannot be sliced anymore
        {
            results.push_back(s);
        }
        for (int i = 1; i < s.length(); i++) // try every possible slice
        {
            string sub = s.substr(i); // sub = s[i:]
            if (words.count(sub))
            {
                string remain = s.substr(0, i); // remain = s[0:i]
                // find all possible results using remain string
                vector<string> subList = dfs(remain, words, memo);
                for (int j = 0; j < subList.size(); j++)
                {
                    results.push_back(subList[j] + " " + sub); // combine them and get the answer
                }
            }
        }
        memo[s] = results; // store to memo
        return results;
    }
};