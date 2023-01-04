class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {  
        /*
            我的方法(大部分人都是這樣解)
            時間複雜度O(n*m)(n:grid的size，m:每個陣列的長度)、空間複雜度O(n*m)
            利用DFS將一個島上的陸地全部探索完，則下次再找到陸地時一定是新的島
        */

        int counter=0;
        vector<vector<bool>> visited(grid.size());
        
        for(int n=0;n<grid.size();n++)
        {
            visited[n]=vector<bool>(grid[n].size(),false);
        }
        
        for(int n=0;n<grid.size();n++)
        {
            for(int k=0;k<grid[n].size();k++)
            {
                if(grid[n][k]=='1'&&!visited[n][k])
                {
                    DFS(n,k,grid,visited);
                    counter++;
                }
            }
        }
        
        return counter;
    }
    
    void DFS(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>& visited)
    {      
        visited[row][col]=true;
        
        if(row+1<grid.size()&&!visited[row+1][col]&&grid[row+1][col]=='1')
        {
            DFS(row+1,col,grid,visited);
        }
        
        if(row-1>=0&&!visited[row-1][col]&&grid[row-1][col]=='1')
        {
            DFS(row-1,col,grid,visited);
        }
        
        if(col+1<grid[row].size()&&!visited[row][col+1]&&grid[row][col+1]=='1')
        {
            DFS(row,col+1,grid,visited);
        }
        
        if(col-1>=0&&!visited[row][col-1]&&grid[row][col-1]=='1')
        {
            DFS(row,col-1,grid,visited);
        }
        
    }
};