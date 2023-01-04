class Solution
{
public:
    int removePalindromeSub(string s)
    {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(1)
            由於字串只有a,b兩種字元組成，所以只需考慮以下情況:
            1. 字串s本來就是迴文，則直接移除整個字串 -> 1個步驟
            2. 字串s本身不是迴文，則先移除所有的a，再移除所有的b -> 2個步驟
            (因為不論有幾個字，只要組成都是同個字元，就一定是回文，
             所以如果這題改成n種字元組合起來的字串，則最多只需n個步驟就能移除)
        */

        if (isPalindrome(s))
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    bool isPalindrome(string &str)
    {
        int i = 0;
        int j = str.length() - 1;

        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};