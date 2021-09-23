class Solution
{
    /*
        參考的方法
        時間複雜度O(m*n*maxMove)、空間複雜度O(m*n*maxMove)
        要注意需要三維的memo，因為在第(i,j)格時，還剩1步和還剩2步的走法不一樣
        (主要就是沒想到這部分，一直用二維memo做不出來)
    */

public:
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        //三維陣列[m][n][maxMove]
        vector<vector<vector<int>>> memo = vector(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

        return move(startRow, startColumn, maxMove, m, n, memo);
    }

    int move(int row, int col, int maxMove, int m, int n, vector<vector<vector<int>>> &memo)
    {
        if (row < 0 || row >= m || col < 0 || col >= n)
        {
            return 1;
        }

        if (maxMove == 0)
        {
            return 0;
        }

        if (memo[row][col][maxMove] != -1)
        {
            return memo[row][col][maxMove];
        }

        //每次做完都要取餘數，避免overflow
        int sum = 0;
        sum += move(row - 1, col, maxMove - 1, m, n, memo);
        sum %= mod;
        sum += move(row + 1, col, maxMove - 1, m, n, memo);
        sum %= mod;
        sum += move(row, col - 1, maxMove - 1, m, n, memo);
        sum %= mod;
        sum += move(row, col + 1, maxMove - 1, m, n, memo);
        sum %= mod;
        memo[row][col][maxMove] = sum;

        return sum;
    }
};