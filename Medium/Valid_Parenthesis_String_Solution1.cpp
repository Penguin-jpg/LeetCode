class Solution
{
    /*
        自己寫的(99%)加上想法參考(1%)
        時間複雜度O(n)、空間複雜度O(n)
        把'('和'*'的位置做紀錄，先讓左括號和右括號配對，如果不夠，
        再用星號配對，最後讓左括號和星號配對
    */

public:
    bool checkValidString(string s)
    {
        stack<int> leftPos;
        stack<int> starPos;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                leftPos.push(i);
            }
            else if (s[i] == ')')
            {
                if (!leftPos.empty())
                {
                    leftPos.pop();
                }
                else if (!starPos.empty())
                {
                    starPos.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                starPos.push(i);
            }
        }

        if (leftPos.size() > starPos.size())
        {
            return false;
        }

        while (leftPos.size() != 0)
        {
            if (leftPos.top() > starPos.top())
            {
                return false;
            }

            leftPos.pop();
            starPos.pop();
        }

        return true;
    }
};