class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
            參考的方法
            時間複雜度O(m*n)，空間複雜度O(m*n)
            到某格的方法數為到他左邊的方法數加上到他上面的方法數，加完後回傳到終點的方法數就好
        */

        //儲存每格方法數
        int grid[m][n];

        //將最上面及最左邊的格子方法數紀錄為1
        for(int i=0;i<m;i++)
        {
            grid[i][0]=1;
        } 
        for(int i=0;i<n;i++)
        {
            grid[0][i]=1;
        }
        
        //算出其他格的方法數
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                grid[i][j]=grid[i-1][j]+grid[i][j-1];
            }
        }
        
        return grid[m-1][n-1];
    }
};