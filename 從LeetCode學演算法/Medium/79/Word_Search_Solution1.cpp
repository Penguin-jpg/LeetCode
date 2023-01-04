class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        /*
            參考的方法(大部分的人都是這樣解)
            m:列數、n:行數、L:字串長度
            時間複雜度O(m*n*3^L)(每個字都有3個方向可以延伸)
            空間複雜度O(m*n+L)
            利用backtracking暴力解
        */

        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        
        for(int row=0;row<board.size();row++)
        {
            for(int col=0;col<board[0].size();col++)
            {
                if(backtracking(board,visited,row,col,0,word))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool backtracking(vector<vector<char>>& board,
                      vector<vector<bool>>& visited,
                      int row,int col,int index,string& word)
    {       
        if(board[row][col]!=word[index])
        {
            return false;
        }
        
        if(index==word.length()-1)
        {
            return true;
        }
        
        visited[row][col]=true;
        
        if(row-1>=0&&!visited[row-1][col]
           &&backtracking(board,visited,row-1,col,index+1,word))
        {
            return true;
        }

        if(row+1<board.size()&&!visited[row+1][col]
           &&backtracking(board,visited,row+1,col,index+1,word))
        {
            return true;
        }

        if(col-1>=0&&!visited[row][col-1]
           &&backtracking(board,visited,row,col-1,index+1,word))
        {
            return true;
        }

        if(col+1<board[0].size()&&!visited[row][col+1]
           &&backtracking(board,visited,row,col+1,index+1,word))
        {
            return true;
        }
        
        visited[row][col]=false;
        
        return false;
    }
};