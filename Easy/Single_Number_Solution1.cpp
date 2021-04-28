class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
            我的方法
            時間複雜度O(n)、空間複雜度O(n)
            先用hashmap將出現次數儲存起來，再從hashmap中找出只出現一次的數
        */

        if(nums.size()==1)
        {
            return nums[0];
        }
        
        unordered_map<int,int> counter;
        unordered_map<int,int>::iterator it;
        
        for(int n=0;n<nums.size();n++)
        {
            counter[nums[n]]++;
        }
        
        for(it=counter.begin();it!=counter.end();it++)
        {
            if(it->second==1)
            {
                break;
            }
        }
        
        return it->first;
    }
};