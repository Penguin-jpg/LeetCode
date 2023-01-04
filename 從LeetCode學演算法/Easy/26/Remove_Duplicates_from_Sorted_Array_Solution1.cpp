class Solution {
public:
    int removeDuplicates(vector<int>& nums) {   
        /*
            我的方法1
            會超時
        */  

        //利用Two Pointers找出相同的數，再做移除
        for(int n=0;n<nums.size()-1;n++)
        {
            for(int k=n+1;k<nums.size();)
            {
                if(nums[n]==nums[k])
                {
                    nums.erase(nums.begin()+k);
                }else
                {
                    k++;
                }
            }
        }
        
        return nums.size();
    }
};