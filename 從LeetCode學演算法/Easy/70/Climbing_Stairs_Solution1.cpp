class Solution {
public:
    int climbStairs(int n) {
        /*
            我的方法
            複雜度O(n)，建表對應方法數
        */
        //對應每種階層的方法數
        int table[45]={1,2,3};
        
        //建立表(爬n階的方法數=爬n-2階的方法數+爬n-1階的方法數
        for(int n=3;n<45;n++)
        {
            table[n]=table[n-2]+table[n-1];
        }
        
        return table[n-1];
    }
};