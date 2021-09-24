class Solution
{
public:
    bool checkValidString(string s)
    {
        /*
            參考的方法2
            時間複雜度O(n)、空間複雜度O(1)
            low: 最小的左括號數量(最少一定要被配對完成的左括號數量)
            high: 最大的左括號數量(最大可能會產生尚未配對的左括號數量)
            
            Ex. '(' -> low = 1, high = 1
                '(*(' -> low = 1, high = 3
                
            The string is valid for 2 condition:
            1. high will never be negative 
            2. low is 0 at the end (No more ')' needed)

            貪婪演算法，找出可能的配對區間，如果能讓low=0(完全配對)，就是true，否則就是false
         */

        int low = 0;
        int high = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(') //遇到左括號
            {
                high++;
                low++;
            }
            else if (s[i] == ')') //遇到右括號
            {
                high--;
                low--;
            }
            else //遇到星號
            {
                //當成左括號
                high++;
                //拿去配對
                low--;
            }

            if (high < 0)
            {
                break;
            }

            //low代表最小的左括號數量，不可能會小於0
            low = max(low, 0);
        }

        return low == 0;
    }
};