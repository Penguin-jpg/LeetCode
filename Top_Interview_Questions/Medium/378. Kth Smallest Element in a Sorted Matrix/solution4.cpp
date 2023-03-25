#include <queue>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 binary search 解，由於答案(ans)是第 k 小的元素，小於等於 ans 的
 * 元素數量>=k 必成立，觀察可知 matrix 左上角為上界；右下角為下界，對該範圍做 binary
 * search 得到 mid (mid 不一定是存在於 matrix 的值)，若此時小於等於 mid 的元素數
 * 量>=k，代表 mid "可能是"答案，但為確保其為真正的答案，我們必須往 mid 的左邊找
 * 是否有更小且符合條件的值；若此時小於等於 mid 的元素數量<k，代表摭取太小，
 * 要往 mid 的右邊找更大且符合條件的值
 * (我們可以利用每個 row 和 column 都是由小到大排序的特性快速計算出小於等於 mid
 * 的元素數量)
 * 時間: O(log(m*n)), 空間: O(1)
 */

class Solution
{
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix[0].size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        int result = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (countLessOrEqual(matrix, mid, n) >= k)
            {
                right = mid - 1; // we need to find if there is a smaller number also satisfies the condition
                result = mid;    // assume current mid is the result
            }
            else
            {
                left = mid + 1; // we need to find if there is a bigger number satisfies the condition
            }
        }
        return result;
    }

    int countLessOrEqual(vector<vector<int>> &matrix, int num, int n)
    {
        int col = n - 1, counter = 0;
        for (int i = 0; i < n; i++)
        {
            // if the matrix[i][col]>num, means that the whole column is bigger
            // than num, so we don't need to check elements in this column
            while (col >= 0 && matrix[i][col] > num)
            {
                col--;
            }
            counter += (col + 1);
        }
        return counter;
    }
};