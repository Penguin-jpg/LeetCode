class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        /*
            我的方法2
            時間複雜度O(n^2)、空間複雜度O(1)
            two pointers
        */

        if(nums.size()==1)
        {
            return nums;
        }
        
        for(int n=0;n<nums.size()-1;n++)
        {
            for(int k=n+1;k<nums.size();k++)
            {
                if(nums[n]%2==1&&nums[k]%2==0)
                {
                    swap(nums[n],nums[k]);
                    break;
                }
            }
        }
        
        return nums;
    }
};