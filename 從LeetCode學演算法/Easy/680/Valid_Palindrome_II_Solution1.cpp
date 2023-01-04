class Solution
{
public:
    /*
        我的方法1
        時間複雜度O(n)、空間複雜度O(n)
        用two pointers從左邊和右邊檢查，
        當檢查到不一樣的字母後，先測試刪除左邊(略過不看)能不能構成迴文，
        不行的話就刪右邊，兩邊都不行就直接回傳false
    */

    bool validPalindrome(string s)
    {
        return recur(s, 0, s.length() - 1, true);
    }

    bool recur(string &s, int left, int right, bool removable)
    {
        if (left >= right)
        {
            return true;
        }

        if (s[left] == s[right])
        {
            return recur(s, left + 1, right - 1, removable);
        }
        else if (removable)
        {
            return recur(s, left + 1, right, false) || recur(s, left, right - 1, false);
        }
        else
        {
            return false;
        }
    }
};