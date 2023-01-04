class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
            我的方法1
            時間複雜度O((k0-2)+(k1-2)+...+(kn-2))(kn:nums[n]的數量)
            空間複雜度O(n)
            用two pointers解
        */

        if(nums.size()<3)
        {
            return nums.size();
        }
        
        unordered_map<int,int> counters;
        int i=0;
        int j=1;
        
        for(int i=0;i<nums.size();i++)
        {
            counters[nums[i]]++;
        }
        
        while(i<nums.size()&&j<nums.size())
        {
            if(nums[i]==nums[j]&&counters[nums[i]]>2)
            {
                nums.erase(nums.begin()+j);
                counters[nums[i]]--;
            }else if(nums[i]==nums[j])
            {
                i+=2;
                j+=2;
            }else
            {
                i++;
                j++;
            }
        }
        
        return nums.size();
    }
};