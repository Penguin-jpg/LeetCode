#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 想法: 先將每個 digit 對應的字母存到 hash map，用 backtracking 的方式遞迴找出所有組合(不需排列)
 * 時間: O(n*(3^n*4^m)), n: 字串中對應到三種字母的字元數量; m: 字串中對應到四種字母的字元數量, 空間: O(3^n*4^m)
 */

class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
        {
            return {};
        }
        unordered_map<char, vector<char>> table = {
            {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}}, {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
        vector<string> results;
        findCombinations(digits, table, 0, "", results);
        return results;
    }

    void findCombinations(string &digits, unordered_map<char, vector<char>> &table, int index, string combination,
                          vector<string> &results)
    {
        if (index >= digits.length())
        {
            if (combination.length() == digits.length())
            {
                results.push_back(combination);
            }
            return;
        }
        for (int i = index; i < digits.length(); i++)
        {
            vector<char> &letters = table[digits[i]];
            for (int j = 0; j < letters.size(); j++)
            {
                findCombinations(digits, table, i + 1, combination + letters[j], results);
            }
        }
    }
};