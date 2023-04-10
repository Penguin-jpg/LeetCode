#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 參考解答: 可用 BFS 解 (因為整個問題可以看成在鄰居之間找最短路徑)，將
 * beginWord 放入 queue 並開始找，取出 queue 的 front，若目前的字是 endWord，則
 * 回傳 counter，否則就將該字的所有鄰居(只差一字元)找出，並放到 queue 中，若最後
 * queue 空了都還是找不到，就回傳 0
 * 這一題比較需要逐個步驟來看才好理解，可以看下面這一篇的例子：
 * https://leetcode.com/problems/word-ladder/solutions/1764371/a-very-highly-detailed-explanation/
 * 時間: O(m^2 * n), m: 字串長度; n: 總字串數
 *  - 每個字串的每個字元都要跑過 (和 endWord 比較) -> m*n
 *  - 字串的每個字元要替換成 a~z -> 26*m
 *  - 總共 m*n*26*m -> m^2 * n
 * 空間: O(m^2 * n)
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
        unordered_set<string> visited; // if word is visited in BFS
        queue<string> q;
        int counter = 1; // how many times we need to change
        q.push(beginWord);
        visited.insert(beginWord);
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
                        if (!visited.count(current) && words.count(current))
                        {
                            q.push(current);
                            visited.insert(current); // mark as visited so others won't visit it again
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