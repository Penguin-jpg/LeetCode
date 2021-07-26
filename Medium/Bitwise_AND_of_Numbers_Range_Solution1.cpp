class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        /*
            我的方法
            時間複雜度O(m)(m:left的bit數)、空間複雜度O(1)
            每次都看最後一個bit，只要發現left~right中的其中一個數的最後一個bit是0，
            整體取AND就會是0，所以可以直接將最後那個位元當成0，相反則當成1，
            當看完一個bit後，left~right中所有數的最後一個bit都可以去掉，所以做右移
        */

        if(left==0)
        {
            return 0;
        }else if(left==right)
        {
            return left;
        }
        
        int result=0;
        int exp=0;
        
        while(left!=0)
        {
            bool foundZero=false;
            for(int i=left;i<=right;i++)
            {
                if(i%2==0)
                {
                    foundZero=true;
                    break;
                }
            }
            
            if(!foundZero)
            {
                if(exp==0)
                {
                    result++;
                }else
                {
                    result+=pow(2,exp);
                }
            }
            
            left=left>>1;
            right=right>>1;                  
            exp++;
        }
        
        return result;
    }
};