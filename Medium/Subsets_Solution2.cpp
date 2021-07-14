class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
            參考的方法2
            時間複雜度O(n*2^n)、空間複雜度O(2^n)
            backtracking
        */

        vector<vector<int>> results;
        vector<int> subset;
        backtrack(results,subset,nums,0);
        
        return results;
    }
    
    void backtrack(vector<vector<int>>& results,vector<int>& subset,
                   vector<int>& nums,int n)
    {
        if(n==nums.size())
        {
            results.push_back(subset);
            return;
        }
        
        backtrack(results,subset,nums,n+1); //不包含nums[n]的subset
        subset.push_back(nums[n]);
        backtrack(results,subset,nums,n+1); //包含nums[n]的subset
        subset.pop_back();
    }
};