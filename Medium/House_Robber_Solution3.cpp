class Solution {
public:
    int rob(vector<int>& nums) {     
        /*
            參考的方法3
            時間複雜度O(n)、空間複雜度O(n)
            遞迴，memorized
        */

        vector<int> memo(nums.size(),-1);
        return getMax(memo,nums,nums.size()-1);
    }
    
    int getMax(vector<int>& memo,vector<int>& nums,int n)
    {
        if(n==0)
        {
            return nums[0];
        }else if(n==1)
        {
            return max(nums[0],nums[1]);
        }else if(memo[n]!=-1)
        {
            return memo[n];
        }
        
        int ans=max(getMax(memo,nums,n-1),getMax(memo,nums,n-2)+nums[n]);
        memo[n]=ans;
        
        return ans;
    }
};