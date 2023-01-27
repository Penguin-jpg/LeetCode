#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 參考解答: solution1的優化版，每次的迴圈都直接對 table[digit] 來做，這樣可以避
 * 免出現長度等於 digits 以外的字串
 * 時間: O(3^n*4^m), 空間: O(3^n*4^m)
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
            results.push_back(combination);
            return;
        }
        vector<char> &letters = table[digits[index]];
        for (int j = 0; j < letters.size(); j++)
        {
            findCombinations(digits, table, index + 1, combination + letters[j], results);
        }
    }
};