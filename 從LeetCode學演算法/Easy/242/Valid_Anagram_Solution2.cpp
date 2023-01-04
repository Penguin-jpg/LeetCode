class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
            我的方法2
            時間複雜度O(n)、空間複雜度O(1)
            1. 只要長度不同就一定不同
            2. 如果兩者每個字母的數量相消後為0，代表兩者相同，否則就是不同
        */

        if(s.length()!=t.length())
        {
            return false;
        }
        
        int table[26]={0};
        
        for(int n=0;n<s.length();n++)
        {
            table[s[n]-'a']++;
            table[t[n]-'a']--;
        }
        
        for(int n=0;n<26;n++)
        {
            if(table[n]<0)
            {
                return false;
            }
        }
        
        return true;
    }
};