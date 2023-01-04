class Solution
{
public:
    bool validPalindrome(string s)
    {
        /*
            我的方法2
            時間複雜度O(n)、空間複雜度O(1)
            方法1的迭代版
        */

        int left = 0;
        int right = s.length() - 1;
        bool removable = true;

        while (left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else if (removable)
            {
                if (helper(s, left + 1, right))
                {
                    left += 2;
                    right--;
                    removable = false;
                }
                else if (helper(s, left, right - 1))
                {
                    left++;
                    right -= 2;
                    removable = false;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    bool helper(string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};