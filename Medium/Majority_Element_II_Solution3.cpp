class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(1)
            使用摩爾投票演算法，找出前兩多的數n1,n2，再檢查出現次數有沒有大於n/3
        */

        int n1=0;
        int n2=1;
        int counter1=0;
        int counter2=0;
        int third=nums.size()/3;
        vector<int> results;
        
        //找出前兩多的數
        for(int n=0;n<nums.size();n++)
        {
            if(nums[n]==n1)
            {
                counter1++;
            }else if(nums[n]==n2)
            {
                counter2++;
            }else if(counter1==0)
            {
                n1=nums[n];
                counter1=1;
            }else if(counter2==0)
            {
                n2=nums[n];
                counter2=1;
            }else
            {
                counter1--;
                counter2--;
            }
        }
        
        counter1=0;
        counter2=0;
        
        //算出實際出現次數
        for(int n=0;n<nums.size();n++)
        {
            if(nums[n]==n1)
            {
                counter1++;
            }else if(nums[n]==n2)
            {
                counter2++;
            }
        }
        
        //檢查出現次數有沒有大於n/3
        if(counter1>third)
        {
            results.push_back(n1);
        }
        if(counter2>third)
        {
            results.push_back(n2);
        }
        
        return results;
    }
};