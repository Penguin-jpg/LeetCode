class Solution {
public:
    unordered_set<int> nums; //紀錄出現過的數字，檢查有沒有死循環
    bool isHappy(int n) {
        /*
            我的方法
            時間複雜度、空間複雜度不確定(計算的次數不太固定)
            用set紀錄出現的數，再檢查有沒有重複出現
        */

        if(n==1) //出現1
        {
            return true;
        }
        
        if(nums.count(n)) //出現循環
        {
            return false;
        }
        
        nums.insert(n); //紀錄目前出現過的數
        
        int sum=0;
        int digit=0;
        while(n>0)
        {
            digit=n%10;
            sum+=digit*digit;
            n/=10;
        }
        
        return isHappy(sum);
    }
};