class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
            我的方法，會超時
            當m=1或n=1時，就只會有一種走法，所以將grid分割到變成m=1或n=1後，再將全部相加
        */

        if(m==1||n==1)   
        {
            return 1;
        }else
        {
            return uniquePaths(m-1,n)+uniquePaths(m,n-1);
        }
    }
};