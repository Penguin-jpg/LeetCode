class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
            我的方法1
            時間複雜度O(n)、空間複雜度O(1)
            分別記錄兩個字串出現的每個字母的數量，再進行比較，如果不同就不是anagram
        */

        int table1[26]={0};
        int table2[26]={0};
        
        for(int n=0;n<s.length();n++)
        {
            table1[s[n]-'a']++;
        }
        
        for(int n=0;n<t.length();n++)
        {
            table2[t[n]-'a']++;
        }
        
        for(int n=0;n<26;n++)
        {
            if(table1[n]!=table2[n])
            {
                return false;
            }
        }
        
        return true;
    }
};