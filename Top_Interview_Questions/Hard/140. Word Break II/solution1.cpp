#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 想法: 用 backtracking 解，由於我不想要直接加入空格到字串中，所以我改用記錄切
 * 割位置的方式來找，令最大切割量為 numSlices，設字串長度為 n，若上一人切到 i，
 * 則這次最多只能切 numSlices-i，將所有可能的切割情況找出即為答案，為方便理解以
 * 下我舉個例子：
 * s="abcdef", wordDict=["a","b","c","ab","bc","def"]
 * 對 'a' 來說，最大切割量為 6，也就是可切成 "a","ab","abc","abcd","abcde","abcdef"，
 * 假設此時從 a 開始選擇切割量為 2，則下一次應該從 'c' 開始，且最大切割量為 4，
 * 也就是可切成 "c","cd","cde","cdef"，以此類推
 * 再來為了要加快檢查 wordDict 的速度，在已知所有元素均獨特下，所以將其轉為 hash
 * set 以幫助快速查詢，當本輪均切完後就把所有 slice 用空白隔開組合起來
 * 時間: 不知道, 空間: 不知道
 */

class Solution
{
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> words(wordDict.begin(), wordDict.end()); // turn wordDict to hash set
        vector<string> results;
        vector<string> slices; // store slices produced during backtracking
        backtracking(s, 0, s.length(), slices, words, results);
        return results;
    }

    void backtracking(string &s, int start, int numSlices, vector<string> &slices, unordered_set<string> &words,
                      vector<string> &results)
    {
        if (start >= s.length())
        {
            string result = "";
            for (int i = 0; i < slices.size(); i++) // concat every slice in slices and separate with whitespace
            {
                result += slices[i] + " ";
            }
            result.pop_back(); // remove the last whitespace
            results.push_back(result);
            return;
        }
        for (int i = 1; i <= numSlices; i++)
        {
            string sub = s.substr(start, i);
            if (words.count(sub)) // check if sub in wordDict
            {
                slices.push_back(sub);
                // next slice should start at (start+i) and max number of slices is (numSlices-i)
                backtracking(s, start + i, numSlices - i, slices, words, results);
                slices.pop_back();
            }
        }
    }
};