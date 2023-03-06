#include <cctype>
#include <stack>
#include <string>
using namespace std;

/**
 * 參考解答: 透過觀察，其實我們在轉 postfix 的過程就已經可以算出答案了，不需要轉完再算
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int calculate(string &s)
    {
        stack<int> nums;
        stack<int> operators;
        // we need to add one more character to the end of s or the loop will
        // end after push last num to nums. we use this "#" to force it enter
        // the loop one more time
        s += "#";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (isdigit(s[i]))
            {
                int num = 0;
                while (isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(num);
                i--; // since we don't have seperator, we need to decrease 1 or i will start at wrong index
            }
            else
            {
                // calculate until meet a higher precedence operator or stack is empty
                while (!operators.empty() && getPrecedence(s[i]) <= getPrecedence(operators.top()))
                {
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    char op = operators.top();
                    operators.pop();
                    if (op == '*')
                    {
                        nums.push(num2 * num1);
                    }
                    else if (op == '/')
                    {
                        nums.push(num2 / num1);
                    }
                    else if (op == '+')
                    {
                        nums.push(num2 + num1);
                    }
                    else
                    {
                        nums.push(num2 - num1);
                    }
                }
                operators.push(s[i]);
            }
        }
        return nums.top();
    }

    int getPrecedence(char ch)
    {
        if (ch == '*' || ch == '/')
        {
            return 3;
        }
        else if (ch == '+' || ch == '-')
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
};