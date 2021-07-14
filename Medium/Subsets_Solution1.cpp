class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
            參考的方法1
            時間複雜度O(n*2^n)、空間複雜度O(n)
            利用backtracking(建議自己trace一次)
        */

        vector<vector<int>> results;
        vector<int> subset;
        
        findSubsets(results,nums,subset,0);
        
        return results;
    }
    
    void findSubsets(vector<vector<int>>& results,vector<int>& nums,
                   vector<int>& subset,int n)
    {
        results.push_back(subset);
        
        if(n==nums.size())
        {
            return;
        }
        
        for(int i=n;i<nums.size();i++)
        {
            subset.push_back(nums[i]);
            findSubsets(results,nums,subset,i+1);
            subset.pop_back();
        }
    }
};