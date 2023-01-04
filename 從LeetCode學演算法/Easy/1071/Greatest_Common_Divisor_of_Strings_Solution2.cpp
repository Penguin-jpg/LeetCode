class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        /*
            參考的方法
            時間複雜度O(len1+len2)、空間複雜度O(len1+len2)
            模擬輾轉相除法，找到符合的就去掉那部分，從後面繼續找
        */

        int len1 = str1.length();
        int len2 = str2.length();

        if (str1 == str2) //兩者相等直接回傳
        {
            return str1;
        }

        if (len1 < len2) //固定讓較長的在第一個參數
        {
            return gcdOfStrings(str2, str1);
        }

        if (str1.substr(0, len2) == str2) //找到common divisor
        {
            return gcdOfStrings(str1.substr(len2), str2);
        }
        else
        {
            return "";
        }
    }
};