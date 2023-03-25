#include <queue>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 max-heap 來存，當 heap 大小為 k 時，後續放入的數有三種情況：
 *      1. matrix[i][j]>heap.top()
 *         若 heap.top() 是第 k 小，則 matrix[i][j] 為第 k+1 小 -> pop
 *      2. matrix[i][j]==heap.top()
 *         若 heap.top() 是第 k 小，則 matrix[i][j] 為第 k 小 -> pop
 *      3. matrix[i][j]<heap.top()
 *         則 heap.top 是第 k+1 小且 matrix[i][j] 是第 k 小 -> pop
 * 觀察後可發現只要將 max-heap 的大小維持在 k，則最後的 top 一定會是答案
 * 時間: O((m*n)log(m*n)), 空間: O(k)
 */

class Solution
{
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> maxHeap;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                maxHeap.push(matrix[i][j]);
                if (maxHeap.size() > k)
                {
                    maxHeap.pop();
                }
            }
        }
        return maxHeap.top();
    }
};