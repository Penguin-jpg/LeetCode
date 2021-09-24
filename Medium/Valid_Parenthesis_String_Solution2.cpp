class Solution
{
public:
    bool checkValidString(string s)
    {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            從左邊看過去，將*都當成左括號一起配對，確定左括號足夠配對，可能有三種情況
            1. 剛好完全配對完 -> leftToRight=0 -> 一定是true
            2. 右括號比較多 -> leftToRight<0 -> 一定是false
            3. 左括號比較多 -> leftToRight>0 -> 可能對可能錯，要進行第二輪檢查
            從右邊看過去，將*都當成右括號一起配對，確定右括號足夠配對，可能有三種情況
            1. 剛好完全配對完 -> rightToLeft=0 -> 一定是true
            2. 右括號比較多 -> rightToLeft>0 -> 一定是true
            3. 左括號比較多 -> rightToLeft<0 -> 一定是false

            為什麼第二輪檢查時，就算rightToLeft>0也是true?
            因為第一輪檢查完時，要是多出來的是左括號，
            在第二輪檢查時就會因為左括號太多而讓整體變成負的，
            所以在經過兩次檢查後可以確定剩下來的部分一定是米字號
        */

        //從左邊看到右邊，把'*'當成左括號，遇到'('和'*'就加1，遇到')'就減1
        int leftToRight = 0;
        //從右邊看到左邊，把'*'當成右括號，遇到'('就減1，遇到')'和'*'就加1
        int rightToLeft = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '*')
            {
                leftToRight++;
            }
            else
            {
                leftToRight--;
            }

            if (leftToRight < 0)
            {
                return false;
            }
        }

        if (leftToRight == 0)
        {
            return true;
        }

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')' || s[i] == '*')
            {
                rightToLeft++;
            }
            else
            {
                rightToLeft--;
            }

            if (rightToLeft < 0)
            {
                return false;
            }
        }

        return true;
    }
};