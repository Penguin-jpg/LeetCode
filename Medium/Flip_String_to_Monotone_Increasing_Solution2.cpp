class Solution {
public:
    int minFlipsMonoIncr(string s) {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(1)
            每個子問題都可以看成兩種情況
            1. 結尾是0 
            2. 結尾是1

            如果是情況1，而且目前是0，就不需要翻轉
            如果是情況2，而且目前是0，就要翻轉

            如果是情況1，而且目前是1，就要翻轉
            如果是情況2，而且目前是1，就看情況1跟情況2哪個翻轉次數比較少(看前面是0比較多還是1比較多)，
            選擇少的那個(簡單來說是決定上一個數字要轉為0還是1會有比較少的翻轉次數)
        */

        int endIn0=0; //結尾為0所需的翻轉次數
        int endIn1=0; //結尾為1所需的翻轉次數
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            {
                endIn1++;
            }else
            {
                endIn1=min(endIn0,endIn1);
                endIn0++;
            }
        }
        
        return min(endIn0,endIn1);
    }
};