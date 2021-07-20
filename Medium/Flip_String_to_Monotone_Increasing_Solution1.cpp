class Solution {
public:
    int minFlipsMonoIncr(string s) {
        /*
            我的方法(會超時)
            時間複雜度O(n^2)、空間複雜度O(1)
        */

        int minFlip=0;
        int one=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                one++;
            }
        }

        minFlip=one; //先假設把1都換成0
        
        //假設nums[i]=1，代表之後都要是1
        for(int i=0;i<s.length();i++)
        {
            int total=s[i]=='0'?1:0;
            
            for(int j=0;j<i;j++)
            {
                if(s[j]=='1')
                {
                    total++;
                }
            }
            
            for(int j=i+1;j<s.length();j++)
            {
                if(s[j]=='0')
                {
                    total++;
                }
            }
            
            if(total<minFlip)
            {
                minFlip=total;
            }
        }
        
        return minFlip;
    }
};