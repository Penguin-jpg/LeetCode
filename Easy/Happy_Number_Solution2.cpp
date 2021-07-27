class Solution {
public:
    
    bool isHappy(int n) {      
        /*
            參考的方法
            時間複雜度不確定，空間複雜度O(m)(m:出現過的數字數量)
            我的方法的迭代版
        */

        unordered_set<int> nums;
        int sum=0;
        int digit=0;
        while(nums.count(n)!=1)
        {
            if(n==1)
            {
                return true;
            }
            
            nums.insert(n);
            while(n>0)
            {
                digit=n%10;
                sum+=digit*digit;
                n/=10;
            }
            n=sum;
            sum=0;
        }
        
        return false;
    }
};