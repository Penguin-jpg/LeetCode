class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            我的方法
            時間複雜度O(n)、空間複雜度O(n)
            紀錄每個數的出現次數，出現次數超過長度一半的數就是答案
        */

        if(nums.size()==1)
        {
            return nums[0];
        }
        
        int half=nums.size()/2;
        unordered_map<int,int> counter;
        unordered_map<int,int>::iterator it;
        
        for(int n=0;n<nums.size();n++)
        {
            counter[nums[n]]++;
        }
        
        for(it=counter.begin();it!=counter.end();it++)
        {
            if(it->second>half)
            {
                break;
            }
        }
        
        return it->first;
    }
};