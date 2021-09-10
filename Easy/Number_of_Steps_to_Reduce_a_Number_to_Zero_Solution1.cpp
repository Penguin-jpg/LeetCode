class Solution
{
public:
    int numberOfSteps(int num)
    {
        /*
            我的方法1
            時間複雜度O(log(n))、空間複雜度O(1)
            照題目規則做
        */

        int counter = 0;

        while (num != 0)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                num--;
            }
            counter++;
        }

        return counter;
    }
};