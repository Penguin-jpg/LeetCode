class Solution {
public:
    int removeDuplicates(vector<int>& nums) { 
        /*
            參考的方法
            不對原陣列做移除，只記錄共多少個不同的數
        */
        //數量小於2的不可能重複
        if(nums.size()<2)
        {
            return nums.size();
        }
        
        //紀錄上一個遇到一樣的數的index(同時用來記錄不一樣的數有幾個)
        int lastSameIndex=0;                                   
        int len=nums.size();
        
        for(int n=1;n<len;n++)
        {
            //檢查目前的數和上一個遇到一樣的數是否相同
            if(nums[n]!=nums[lastSameIndex])
            {
                lastSameIndex++;
                //避免重複計算
                nums[lastSameIndex]=nums[n];
            }
        }
        
        //加1是為了把剛開始判定為一樣的那個數加回來
        return lastSameIndex+1;
    }
};