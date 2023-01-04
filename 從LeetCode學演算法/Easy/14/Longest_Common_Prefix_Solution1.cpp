class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
            我的方法
            複雜度:O(最長字串長度 * 總字串數)
        */
        string prefix="";
        int len=strs.size();
        string compare="";
        int counter=0;
        int maxLen=0;
        bool found=true;
        
        //找出最長的字串
        for(int n=0;n<len;n++)
        {  
            if(strs[n].length()>compare.length())
            {
                compare=strs[n];
            }
        }
        
        maxLen=compare.length();
        
        //找出最長的common prefix
        for(int n=0;n<maxLen;n++)
        {
            for(int k=0;k<len;k++)
            {
                //當目前字串長度太小就換下一個字串
                if(strs[k].length()<=n)
                {
                    continue;
                }
                
                if(strs[k][n]==compare[n])
                {
                    counter++;
                }else
                {
                    found=false;
                    break;
                }
            }
            //prefix中斷就break
            if(!found)
            {
                break;
            }else if(counter==len)
            {
                prefix+=compare[n];
            }    
            counter=0;
        }
        return prefix;
    }
};