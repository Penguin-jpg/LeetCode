#include <queue>
#include <utility>
#include <vector>
using namespace std;

/**
 * 想法: 用 BFS 解，當找到"1"時，就把這個所有相連的"1"都找出來改成"x"，找的方式
 * 為從 queue 中取出一個點，並把上下左右的"1"都放到 queue，持續做到最後就能把整塊"1"都改成"x"
 * 時間: O(m*n), 空間: O(n)
 */

class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), counter = 0;
        pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> points;
        int row = 0, col = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    counter++;
                    points.push({i, j});
                    while (!points.empty())
                    {
                        pair<int, int> current = points.front();
                        points.pop();
                        for (int i = 0; i < 4; i++)
                        {
                            row = current.first + directions[i].first;
                            col = current.second + directions[i].second;
                            if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != '1')
                            {
                                continue;
                            }
                            grid[row][col] = 'x';
                            points.push({row, col});
                        }
                    }
                }
            }
        }
        return counter;
    }
};