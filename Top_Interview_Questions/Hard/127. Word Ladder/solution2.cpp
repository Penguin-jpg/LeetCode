#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 參考解答: 其實可以直接把 words 這個 hash set 同時當成 visited 和 wordList，只
 * 要走過的就從其中刪除，這樣就能做到 visited 的效果
 * 時間: O(m^2 * n), m: 字串長度; n: 總字串數, 空間: O(m^2 * n)
 */

class Solution
{
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // all words are unique in wordList, so hash set is good enough
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) // if wordList does not contain endWord
        {
            return 0;
        }
        queue<string> q;
        int counter = 1; // how many times we need to change
        q.push(beginWord);
        words.insert(beginWord);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string current = q.front();
                q.pop();
                if (current == endWord)
                {
                    return counter;
                }
                // find all neighbors of current
                for (int j = 0; j < current.length(); j++)
                {
                    char temp = current[j];
                    for (int k = 0; k < 26; k++)
                    {
                        current[j] = 'a' + k;
                        if (words.count(current))
                        {
                            q.push(current);
                            words.erase(current); // mark as visited so others won't visit it again
                        }
                    }
                    current[j] = temp;
                }
            }
            counter++;
        }
        return 0;
    }
};