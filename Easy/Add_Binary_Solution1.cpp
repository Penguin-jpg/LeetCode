class Solution {
public:
    string addBinary(string a, string b) {
        /*
            我的方法
            複雜度:O(max(a.length(),b.length()))，in-place，先將兩字串相加後，再處理進位
        */
        //處理至少一個為0的狀況
        if(a=="0")
        {
            return b;
        }else if(b=="0")
        {
            return a;
        }
        
        //用in-place，不新增新的字串，只操作原字串
        if(a.length()<=b.length())
        {
            add(a,b);
            carry(b);
            return b;
        }else
        {
            add(b,a);
            carry(a);
            return a;
        }
    }
    
    //兩字串相加
    void add(string& str1,string& str2)
    {
        //讓長度較小的字串加到較大的字串內
        for(int n=str1.length()-1,k=str2.length()-1;n>=0;n--,k--)
        {
            str2[k]=((str1[n]-'0')+(str2[k]-'0'))+'0';
        }
    }
    
    //計算進位
    void carry(string& str)
    {
        for(int n=str.length()-1;n>0;n--)
        {
            //找出需要進位的位置
            if(str[n]-'0'>1)
            {
                str[n-1]=((str[n-1]-'0')+1)+'0';
                str[n]=((str[n]-'0')%2)+'0';
            }
        }
        
        //開頭的進位要另外處理(因為要插入一個新字元在開頭)
        if(str[0]-'0'>1)
        {
            str[0]=((str[0]-'0')%2)+'0';
            str.insert(str.begin(),'1');
        }
    }
};