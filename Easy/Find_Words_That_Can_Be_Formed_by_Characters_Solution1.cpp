class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        /*
            我的方法
            時間複雜度O(n)，n是所有word的長度總和
            空間複雜度O(1)
        */

        bool found=true;
        int pos=0;
        int sum=0;
        
        for(int n=0;n<words.size();n++)
        {
            string temp=chars;
            for(int k=0;k<words[n].length();k++)
            {
                pos=temp.find(words[n][k]);
                if(pos!=string::npos)
                {
                    temp[pos]='-';
                }else
                {
                    found=false;
                    break;
                }
            }
            
            if(found)
            {
                sum+=words[n].length();
            }
            
            found=true;
        }
        
        return sum;
    }
};