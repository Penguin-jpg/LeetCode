class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        /*
            參考的方法
            時間複雜度O(n)(n:總單字數)、空間複雜度O(n)(n:總單字數)
            利用stringstream會切空格的特性來達到字串切割，但要記得先把特殊符號都換空格
        */

        string word="";
        string result="";
        unordered_map<string,int> counters;
        int maxNum=0;
        
        for(int n=0;n<paragraph.length();n++)
        {
            if(isalpha(paragraph[n]))
            {
                paragraph[n]=tolower(paragraph[n]);
            }else
            {
                paragraph[n]=' ';
            }
        }
        
        stringstream ss(paragraph);
        
        while(ss>>word)
        {   
            counters[word]++;
        }
        
        for(int n=0;n<banned.size();n++)
        {
            counters[banned[n]]=INT_MIN;
        }
        
        for(auto& it:counters)
        {
            if(it.second>maxNum)
            {
                maxNum=it.second;
                result=it.first;
            }
        }
        
        return result;
    }
};