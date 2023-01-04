class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(1)
            上一種方法的簡化版
        */

        if(s.length()!=t.length())
        {
            return false;
        }
        
        int table[26]={0};
        
        for(int n=0;n<s.length();n++)
        {
            table[s[n]-'a']++;
        }
        
        for(int n=0;n<t.length();n++)
        {
            table[t[n]-'a']--;
            if(table[t[n]-'a']<0)
            {
                return false;
            }
        }
        
        return true;
    }
};