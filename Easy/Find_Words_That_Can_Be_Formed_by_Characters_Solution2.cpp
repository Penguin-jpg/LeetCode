class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        /*
            參考的方法
            空間複雜度O(n)，n是所有word的長度總和
            空間複雜度O(1)
            模擬Hash Table
            算出chars中每個字母的出現次數，在檢查每個word是否有超出這些次數
        */

        int counter[26]={0};
        int sum=0;
        
        //算出每個字母出現的次數
        for(int n=0;n<chars.length();n++)
        {
            counter[chars[n]-'a']++;
        }
        
        for(int n=0;n<words.size();n++)
        {
            sum+=check(words[n],counter);
        }
        
        return sum;
    }
    
    int check(string& word,int* counter)
    {
        int wordCounter[26]={0};
        for(int n=0;n<word.length();n++)
        {
            wordCounter[word[n]-'a']++;
            //如果出現次數比現有的還多，代表不合格
            if(wordCounter[word[n]-'a']>counter[word[n]-'a'])
            {
                return 0;
            }
        }
        
        return word.length();
    }
};