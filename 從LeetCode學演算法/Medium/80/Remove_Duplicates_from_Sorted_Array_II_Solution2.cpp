class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
            我的方法2
            時間複雜度O((k0-2)+(k1-2)+...+(kn-2))(kn:nums[n]的數量)
            空間複雜度O(1)
        */

        if(nums.size()==1)
        {
            return 1;
        }
        
        int i=0;
        int j=1;
        
        while(i<nums.size()&&j<nums.size())
        {
            if(nums[i]==nums[j]&&j-i>=2)
            {
                nums.erase(nums.begin()+j);
            }else if(nums[i]==nums[j])
            {
                j++;
            }else
            {
                i++;
            }
        }
        
        return nums.size();
    }
};