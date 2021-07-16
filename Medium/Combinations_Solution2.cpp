class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        /*
            我的方法2
            時間複雜度O(n*2^k)、空間複雜度O(n+2^k) (空間複雜度不確定有沒有分析正確)
            利用backtracking來做
        */

        vector<vector<int>> results;
        vector<int> nums(n);
        
        for(int i=0;i<n;i++)
        {
            nums[i]=i+1;
        }
        
        if(n==k)
        {
            results.push_back(nums);
            return results;
        }
        
        vector<int> comb;
        backtracking(results,nums,comb,0,k,0);
        
        return results;
    }
    
    void backtracking(vector<vector<int>>& results,vector<int>& nums,
                      vector<int>& comb,int n,int k,int index)
    {
        if(index==k)
        {
            results.push_back(comb);
            return;
        }
            
        for(int j=n;j<nums.size();j++)
        {
            comb.push_back(nums[j]);
            backtracking(results,nums,comb,j+1,k,index+1);
            comb.pop_back();
        }
    }
};