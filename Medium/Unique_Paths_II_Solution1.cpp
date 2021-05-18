class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {  
        /*
            我的方法(這題做的方法基本上都一樣)
            時間複雜度O(m*n)、空間複雜度O(m*n)
            每格都只有兩種走法，往右或往下(除了最外圍是一種走法)，
            如果在最外圍遇到障礙物，則從障礙物後的幾格不可能走到，
            最後將總走法加總起來就答案
        */
       
        //起點就有障礙物，直接回傳0
        if(obstacleGrid[0][0]==1)
        {
            return 0;
        }

        //使用變數當作長度的陣列不能初始化
        int table[obstacleGrid.size()][obstacleGrid[0].size()];
        
        //紀錄最上排走法
        for(int n=0;n<obstacleGrid.size();n++)
        {
            if(obstacleGrid[n][0]==1)
            {
                for(int k=n;k<obstacleGrid.size();k++)
                {
                    table[k][0]=0;
                }
                break;
            }else
            {
                table[n][0]=1;
            }
        }
        
        //紀錄最左邊那排的走法
        for(int n=0;n<obstacleGrid[0].size();n++)
        {
            if(obstacleGrid[0][n]==1)
            {
                for(int k=n;k<obstacleGrid[0].size();k++)
                {
                    table[0][k]=0;
                }
                break;
            }else
            {
                table[0][n]=1;
            }
        }
        
        //算出總走法
        for(int n=1;n<obstacleGrid.size();n++)
        {
            for(int k=1;k<obstacleGrid[n].size();k++)
            {
                //遇到障礙物舊紀錄為0
                if(obstacleGrid[n][k]==1)
                {
                    table[n][k]=0;
                }else
                {
                    //這格的走法為這格左邊的走法加這格上面的走法
                    table[n][k]=table[n-1][k]+table[n][k-1];
                } 
            }
        }
        
        return table[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};