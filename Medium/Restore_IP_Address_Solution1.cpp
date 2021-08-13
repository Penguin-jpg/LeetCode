class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        /*
            參考的方法
            時間複雜度O(length of s)、空間複雜度O(length of s)
            backtracking
        */

        vector<string> results;

        findIP(results, s, "", 0, 0);

        return results;
    }

    void findIP(vector<string> &results, string &s, string last, int counter, int pos)
    {
        if (counter > 4)
        {
            return;
        }

        if (pos == s.size() && counter == 4)
        {
            last.pop_back(); //去掉最後一個點
            results.push_back(last);
            return;
        }

        for (int i = 1; i <= 3 && pos + i <= s.length(); i++)
        {
            string temp = s.substr(pos, i); //要使用的區段

            if (temp.length() > 1 && temp[0] == '0') //出現leading zero的情況
            {
                continue;
            }

            int val = stoi(temp); //將區段轉換成數字

            if (val <= 255)
            {
                string current = last + temp + ".";                //接到IP上
                findIP(results, s, current, counter + 1, pos + i); //繼續找下一段
            }
        }
    }
};