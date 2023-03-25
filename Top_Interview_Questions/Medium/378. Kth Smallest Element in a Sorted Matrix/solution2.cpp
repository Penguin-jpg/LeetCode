#include <queue>
#include <vector>
using namespace std;

/**
 * 想法: 存到 min-heap 內，這樣存完的同時也排完了，只需要 pop k-1 次即為答案 (不符合題目要求的空間複雜度小於 O(m*n))
 * 時間: O((m*n)log(m*n)+k), 空間: O(m*n)
 */

class Solution
{
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                minHeap.push(matrix[i][j]);
            }
        }
        for (int i = 0; i < k - 1; i++)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};