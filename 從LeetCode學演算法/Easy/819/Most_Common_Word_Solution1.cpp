class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        /*
            我的方法
            時間複雜度O(n)(n:總單字數)、空間複雜度O(n)(n:總單字數)
            先對paragraph做字串切割，並記錄次數，找出出現最多次的(banned出現次數為INT_MIN，不可能為最大)
        */

        unordered_map<string,int> counters;
        string maxStr="";
        int maxNum=0;
        
        for(int n=0;n<banned.size();n++)
        {
            counters[banned[n]]=INT_MIN;
        }
        
        split(counters,paragraph);
        
        for(auto& it:counters)
        {
            if(it.second>maxNum)
            {
                maxNum=it.second;
                maxStr=it.first;
            }
        }
        
        return maxStr;
    }
    
    void split(unordered_map<string,int>& counters,string& paragraph)
    {
        int current=0;
        int pos=0;
        string temp="";
        
        while(true)
        {
            pos=paragraph.find_first_of(" !?',;.",current);
            
            if(pos!=current)
            {
                temp=paragraph.substr(current,pos-current);
                
                if(temp.length()!=0)
                {
                    for(int n=0;n<temp.length();n++)
                    {
                        temp[n]=tolower(temp[n]);
                    }
                    counters[temp]++;
                }
            }
            
            if(pos==string::npos)
            {
                break;
            }
            
            current=pos+1;
        }
    }
};