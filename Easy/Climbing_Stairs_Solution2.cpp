class Solution {
public:
    int climbStairs(int n) {
        /*
            參考的方法:
            複雜度O(n)，用費式數列解(跟建表原理相同)
        */
        if(n<3)
        {
            return n;
        }
        
        int step1=1;
        int step2=2;
        int ans=0;
        
        for(int k=3;k<=n;k++)
        {
            ans=step1+step2;
            step1=step2;
            step2=ans;
        }
        return ans;
    }
};