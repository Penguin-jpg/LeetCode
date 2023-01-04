class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
            參考的方法
            複雜度:O((總字串數-1) * len)
        */
        if(strs.empty())//先檢查strs是否有字串，沒有就回傳空字串
        {
            return "";
        }
        int len=strs[0].length();//先假設共同的prefix是整個strs[0]字串
        bool end=false;//檢查是否要直接結束迴圈
        for(int n=1;n<strs.size();n++)
        {
            for(int k=0;k<len;k++)
            {
                /*
                用strs[0]和後面幾個字串兩兩比對，如果不一樣，
                代表目前能確定的最長prefix是strs[0][0]到strs[0][k-1]，
                所以將len更改為k，並回頭與下個字串比較
                */
                if(strs[0][k]!=strs[n][k])
                {
                    len=k;
                    if(len==0)//找不到任何共同的prefix，代表不需要找了
                    {
                        end=true;
                        break;
                    }
                }
            }
            if(end==true)
            {
                break;
            }
        }
        return strs[0].substr(0,len);//回傳strs[0][0]~strs[0][len-1]
    }
};