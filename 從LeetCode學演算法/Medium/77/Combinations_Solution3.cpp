class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        /*
            參考的方法
            時間複雜度O(C(n,k))、空間複雜度O(k*C(n,k))
        */

        vector<vector<int>> results;
        vector<int> comb;
        findCombs(results,comb,n,k,1);
        
        return results;
    }
    
    void findCombs(vector<vector<int>>& results,vector<int>& comb,int n,int k,int i)
    {
        if(k==0)
        {
            results.push_back(comb);
        }else if(i+k-1<=n)
        {
            comb.push_back(i);
            findCombs(results,comb,n,k-1,i+1); //有i的情況
            comb.pop_back();
            findCombs(results,comb,n,k,i+1); //沒有i的情況
        }
    }
};