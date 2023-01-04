class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*
            參考的方法
            時間複雜度O(m*n)(m:row數量、n:col數量)、時間複雜度O(1)
            整題的重點在於需要改變的格子要用另一個符號來表示，而不是直接改成0或1
        */

        //8個方向(左上到右下，不包含中間)
        int xDir[]={-1,0,1,-1,1,-1,0,1};
        int yDir[]={-1,-1,-1,0,0,1,1,1};
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                int live=0; //活著的數量
                int dead=0; //死掉的數量
                int targetX=0;
                int targetY=0;

                //檢查8個方向的鄰居
                for(int k=0;k<8;k++)
                {
                    targetX=i+xDir[k];
                    targetY=j+yDir[k];
                    if(targetX>=0&&targetX<board.size()
                       &&targetY>=0&&targetY<board[0].size())
                    {
                        //計算活著和死亡的數量
                        if(board[targetX][targetY]==0||board[targetX][targetY]==-1)
                        {
                            dead++;
                        }else
                        {
                            live++;
                        }
                    }
                }
                
                if(board[i][j]==0)
                {
                    if(live==3)
                    {
                        /* -1代表原本是0後來變成1
                           需要先用另一個符號代替的原因是這題在概念上是同時做，
                           也就是雖然知道這格之後會死，但在當下那個瞬間他仍然是活著的，
                           如果直接改掉的話會導致後面的判斷一起出問題
                        */
                        board[i][j]=-1; 
                    }
                }else
                {
                    if(live<2||live>3)
                    {
                        board[i][j]=-2; //-2代表原本是1後來變成0
                    }
                }
            }
        }
        
        //將-1和-2改回對應的符號上
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==-1)
                {
                    board[i][j]=1;
                }else if(board[i][j]==-2)
                {
                    board[i][j]=0;
                }
            }
        }
    }
};