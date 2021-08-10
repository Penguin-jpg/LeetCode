class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        /*
            我的方法
            時間複雜度O(length of s + length of t)、空間複雜度O(1)
        */

        if (s == t || s == "")
        {
            return true;
        }
        else if (t == "")
        {
            return false;
        }

        int found = -1;

        for (int i = 0; i < s.length(); i++)
        {
            found = t.find(s[i], found + 1);

            if (found == string::npos)
            {
                return false;
            }
        }

        return true;
    }
};