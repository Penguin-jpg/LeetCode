class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { 
        /*
            我的方法
            時間複雜度O(mlog(n))(m:row的數量、n:col的數量)、空間複雜度O(1)
            對每個row做二元搜尋
        */

        for(int i=0;i<matrix.size();i++)
        {
            int begin=0;
            int end=matrix[0].size()-1;
            int mid=(begin+end)/2;
            
            while(begin<=end)
            {
                if(matrix[i][mid]==target)
                {
                    return true;
                }else if(matrix[i][mid]<target)
                {
                    begin=mid+1;
                }else
                {
                    end=mid-1;
                }
                
                mid=(begin+end)/2;
            }
        }
        
        return false;
    }
};