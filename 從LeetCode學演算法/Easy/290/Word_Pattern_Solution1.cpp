class Solution {
public:
    bool wordPattern(string pattern, string s) {
        /*
            我的方法
            時間複雜度O(n)(n:s字串長度)、空間複雜度O(n)
        */

        unordered_map<string,char> match1;
        unordered_map<char,string> match2;
        stringstream ss(s);
        string token;
        vector<string> strs;
        
        while(ss>>token)
        {
            strs.push_back(token);
        }
        
        //由長度可知pattern不合
        if(strs.size()!=pattern.length())
        {
            return false;
        }
        
        //雙向都要是1對1
        for(int i=0;i<pattern.length();i++)
        {
            if(match1.count(strs[i])==0&&match2.count(pattern[i])==0)
            {
                match1[strs[i]]=pattern[i];
                match2[pattern[i]]=strs[i];
            }else if(match1[strs[i]]!=pattern[i]||match2[pattern[i]]!=strs[i])
            {
                return false;
            }
        }
        
        return true;
    }
};