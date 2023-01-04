class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /*
            我的方法(大部分人都是這樣解)
            時間複雜度O(n)(n:字串長度)、空間複雜度(n)
            利用unordered_map紀錄每個字母對應的替換字母
        */

        //規則:
        //1. 每個字元都一定要被替換
        //2. 一個字母只能對應到一個字母
        //規則2的例子: 例如:s="Ia",t="ll"，由於'l'已經先對應到'I'，所以'a'就不能對應到'l'
        //3. 字元的順序不能改變
        //4. 大小寫視為不同字母(試出來的)
        
        unordered_map<char,char> s_used; //以s的角度來看字是否用過
        unordered_map<char,char> t_used; //以t的角度來看字是否用過
        
        for(int i=0;i<s.length();i++)
        {
            if(s_used[s[i]]==0&&t_used[t[i]]==0) //如果還沒被替換過，就紀錄要替換上去的字
            {
                //因為規則2，所以需要雙向紀錄
                s_used[s[i]]=t[i];
                t_used[t[i]]=s[i];
            }else if(s_used[s[i]]!=t[i]||t_used[t[i]]!=s[i]) //不論從s或從t來看都要符合規則
            {
                return false;
            }
        }
        
        return true;
    }
};