#include <cctype>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/**
 * 參考解答: 可以將 solution2 的方式更加精簡，我們多用一個變數紀錄運算子，
 * 若為 "+"，就將數字直接 push 到 stack；若為 "-"，就將負的該數 push
 * 到 stack；若為 "*"，就將 stack 的 top 乘上該數；若為 "/"，就將 stack 的 top
 * 除上該數，最後將 stack 中的所有數字相加即可
 * (若覺得難以理解，可以稍微用一些例子帶就會發現確實和先前做的概念相同)
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int calculate(string &s)
    {
        istringstream iss(s); // we utilize iss to convert string to number easily and remove white space
        stack<int> nums;
        char op = '+'; // operator, use "+" as default so it won't mess up the first number
        int num = 0;   // store number
        int result = 0;
        while (iss >> num) // while there is a string can be converted to number
        {
            if (op == '+')
            {
                nums.push(num);
            }
            else if (op == '-')
            {
                nums.push(-num);
            }
            else
            {
                int num2 = nums.top();
                nums.pop();
                if (op == '*')
                {
                    nums.push(num2 * num);
                }
                else
                {
                    nums.push(num2 / num);
                }
            }
            iss >> op; // there is always an operator after a number except for the last number
        }
        while (!nums.empty())
        {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};