class Solution
{
public:
    int numberOfSteps(int num)
    {
        /*
            我的方法2
            時間複雜度O(log(n))、空間複雜度O(1)
            奇數的最後一個位元為1，所以只要看最後一個位元是否為1，就能知道是奇數還是偶數，
            比方法1快非常多
        */

        int counter = 0;

        while (num != 0)
        {
            if (num & 1)
            {
                num--;
            }
            else
            {
                num /= 2;
            }
            counter++;
        }

        return counter;
    }
};