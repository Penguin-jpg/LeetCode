class Solution
{
    /*
        我的方法
        時間複雜度O(4^n)(n:maxMove)、空間複雜度O(n)
        會超時
    */

public:
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return move(startRow, startColumn, maxMove, m, n);
    }

    int move(int row, int col, int maxMove, int m, int n)
    {
        if (row < 0 || row >= m || col < 0 || col >= n)
        {
            return 1;
        }

        if (maxMove == 0)
        {
            return 0;
        }

        int sum = 0;
        sum += move(row - 1, col, maxMove - 1, m, n) % mod;
        sum += move(row + 1, col, maxMove - 1, m, n) % mod;
        sum += move(row, col - 1, maxMove - 1, m, n) % mod;
        sum += move(row, col + 1, maxMove - 1, m, n) % mod;

        return sum % mod;
    }
};