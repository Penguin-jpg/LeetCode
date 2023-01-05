#include <stack>
#include <string>
using namespace std;

/**
 * 想法: 要確認兩兩都能配對且括號的順序必須正確(也就是 "([)]" 這種情況是不行
 * 的)，所以使用 stack 來處理，遇到左括號時就加到 stack 內，當遇到右括號時，就檢
 * 查 stack 的 top 是否為對應的左括號，若不是，就代表無法配對或順序不正確
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> parentheses;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                parentheses.push(s[i]);
            }
            else if (parentheses.empty()) // found close bracket but not found open bracket
            {
                return false;
            }
            else if ((s[i] == ')' && parentheses.top() != '(') || (s[i] == ']' && parentheses.top() != '[') ||
                     (s[i] == '}' && parentheses.top() != '{')) // found close bracket and there are open brackets
            {
                return false;
            }
            else
            {
                parentheses.pop();
            }
        }
        return parentheses.empty(); // should be empty if every close bracket has a corresponding open bracket
    }
};