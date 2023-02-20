#include <stack>
#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 改成遞迴
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> result;
        return calculate(tokens, 0, result);
    }

    bool isNumber(string &str)
    {
        return (str[0] == '-' && str[1] >= '0' && str[1] <= '9') || (str[0] >= '0' && str[0] <= '9');
    }

    bool isOperator(string &str)
    {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }

    int calculate(vector<string> &tokens, int index, stack<int> &result)
    {
        if (index >= tokens.size())
        {
            return result.top();
        }
        if (isOperator(tokens[index]))
        {
            int first = result.top();
            result.pop();
            int second = result.top();
            result.pop();
            if (tokens[index] == "+")
            {
                result.push(second + first);
            }
            else if (tokens[index] == "-")
            {
                result.push(second - first); // order is important
            }
            else if (tokens[index] == "*")
            {
                result.push(second * first);
            }
            else if (tokens[index] == "/")
            {
                result.push(second / first);
            }
        }
        else
        {
            result.push(stol(tokens[index]));
        }
        return calculate(tokens, index + 1, result);
    }
};