class Solution {
public:
    int countPrimes(int n) {
        /*
            我的方法(大部分的人都是這樣解)
            時間複雜度O(nlog(log(n)))、空間複雜度O(n)
            先建表，在看表中2~(n-1)中有哪些為質數
        */

        if(n<2)
        {
            return 0;
        }
        
        vector<bool> table(n,true);
        int counter=0;
        
        makeTable(table,n);
        
        for(int k=2;k<n;k++)
        {
            if(table[k])
            {
                counter++;
            }
        }
        
        return counter;
    }
    
    void makeTable(vector<bool>& table,int n)
    {
        table[0]=false;
        table[1]=false;
        for(long long int k=2;k<n;k++)
        {
            if(table[k])
            {
                //將k的倍數直接記錄為非質數
                for(long long int m=k*k;m<n;m+=k)
                {
                    table[m]=false;
                }
            }
        }
    }
};