#include <stack>
#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 本題是用 postfix 的方式來表示四則運算，只要遇到數字就放到 stack 內，當
 * 遇到運算子時，取 stack 最上方的兩個做該運算，再將結果放回 stack，重複直到所有
 * token 都被執行過一次，就會得到結果
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> result;
        for (int i = 0; i < tokens.size(); i++)
        {
            // since there are only two kind of string, we can choose to check
            // if it is operator or number.
            // but check for operator should be a little faster for my implementation
            if (isOperator(tokens[i]))
            {
                int first = result.top();
                result.pop();
                int second = result.top();
                result.pop();
                if (tokens[i] == "+")
                {
                    result.push(second + first);
                }
                else if (tokens[i] == "-")
                {
                    result.push(second - first); // order is important
                }
                else if (tokens[i] == "*")
                {
                    result.push(second * first);
                }
                else if (tokens[i] == "/")
                {
                    result.push(second / first);
                }
            }
            else
            {
                result.push(stol(tokens[i]));
            }
        }
        return result.top();
    }

    bool isNumber(string &str)
    {
        return (str[0] == '-' && str[1] >= '0' && str[1] <= '9') || (str[0] >= '0' && str[0] <= '9');
    }

    bool isOperator(string &str)
    {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
};