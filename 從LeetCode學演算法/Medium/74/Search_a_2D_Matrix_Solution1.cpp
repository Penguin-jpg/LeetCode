class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
            我的方法1
            時間複雜度O(mlog(n))(m:列數、n:行數)、空間複雜度O(1)
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