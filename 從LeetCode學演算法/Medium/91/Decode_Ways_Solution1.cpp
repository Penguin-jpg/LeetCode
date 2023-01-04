class Solution
{
public:
    int numDecodings(string s)
    {
        unordered_map<string, int> memo;
        return decode(s, s, 0, memo);
    }

    int decode(string &s, string remain, int currentPos, unordered_map<string, int> &memo)
    {
        /*
            我的方法
            時間複雜度O(n)(n:字串s的長度)、空間複雜度O(n)
            測試每個可切割的2位數，再檢查是否在1~26的範圍內，從切完後剩下的部分繼續找，
            透過memo紀錄做過的字串以節省做的次數
        */

        //開頭為0
        if (remain[0] == '0')
        {
            memo[remain] = 0;
            return 0;
        }

        //memo內找不到
        if (memo.count(remain) != 0)
        {
            return memo[remain];
        }

        //找到底了
        if (currentPos == s.length())
        {
            return 1;
        }

        int sum = 0;

        //最多為兩位數
        for (int i = 1; i <= 2; i++)
        {
            //超出範圍
            if (currentPos + i > s.length())
            {
                break;
            }

            string temp = s.substr(currentPos, i); //切出的部分
            remain = s.substr(currentPos + i);     //剩下的部分

            if (temp[0] == '0')
            {
                continue;
            }

            int val = stol(temp);

            //在1~26內
            if (val > 26)
            {
                continue;
            }

            sum += decode(s, remain, currentPos + i, memo);
            memo[remain] = sum;
        }

        return sum;
    }
};