class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
            參考的方法
            時間複雜度O(m+n)(m:row的數量、n:col的數量)、空間複雜度O(1)
            先從每列的最大開始看，如果比target大，就往左邊那行找，
            如果比target小，就往下一列找
        */

        int i=0;
        int j=matrix[0].size()-1;
        
        while(i<matrix.size()&&j>=0)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }else if(matrix[i][j]<target)
            {
                i++;
            }else
            {
                j--;
            }
        }
        
        return false;
    }
};