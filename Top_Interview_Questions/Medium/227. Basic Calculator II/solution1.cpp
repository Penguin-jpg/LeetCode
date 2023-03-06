#include <cctype>
#include <stack>
#include <string>
using namespace std;

/**
 * 參考解答: 先轉 postfix，再計算，不過為了確保哪個數字是分開的，會加入逗點當做斷點
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int calculate(string &s)
    {
        s = toPostfix(s);
        stack<int> nums;
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                int num = 0;
                while (isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(num); // we don't need to do i-- because we can skip seperator
            }
            else
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                if (s[i] == '*')
                {
                    nums.push(num2 * num1);
                }
                else if (s[i] == '/')
                {
                    nums.push(num2 / num1);
                }
                else if (s[i] == '+')
                {
                    nums.push(num2 + num1);
                }
                else
                {
                    nums.push(num2 - num1);
                }
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

    string toPostfix(string &s)
    {
        stack<char> operators;
        string postfix = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ') // skip whitespace
            {
                continue;
            }
            else if (isdigit(s[i])) // add digit
            {
                postfix += s[i];
            }
            else
            {
                postfix += ','; // use "," to seperate numbers
                // pop and store until find a higher precedence operator or
                // stack is empty
                while (!operators.empty() && getPrecedence(s[i]) <= getPrecedence(operators.top()))
                {
                    postfix += operators.top(), operators.pop();
                }
                operators.push(s[i]);
            }
        }
        postfix += ',';
        while (!operators.empty()) // add remaining operators
        {
            postfix += operators.top(), operators.pop();
        }
        return postfix;
    }
};