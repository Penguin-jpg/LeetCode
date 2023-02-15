#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 用 backtracking，取出子字串後檢查其是否為回文，若不是就將長度加一繼續
 * 切，若全部切完都是就放到陣列裡
 * 時間: O(2^n), 空間: O(n)
 */

class Solution
{
  public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> results;
        vector<string> temp;
        backtracking(s, 0, temp, results);
        return results;
    }

    bool isPalindrome(string &s)
    {
        int i = 0, j = s.length() - 1;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++, j--;
        }
        return true;
    }

    void backtracking(string &s, int index, vector<string> &temp, vector<vector<string>> &results)
    {
        if (index >= s.length())
        {
            results.push_back(temp);
            return;
        }

        for (int i = 1; i <= s.length() && index + i <= s.length(); i++)
        {
            string sub = s.substr(index, i);
            if (isPalindrome(sub))
            {
                temp.push_back(sub);
                backtracking(s, index + i, temp, results);
                temp.pop_back();
            }
        }
    }
};