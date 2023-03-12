#include <vector>
using namespace std;

/**
 * 想法: 由於每個 row 跟 column 都已經排序完成，所以直接對每個 row 做 binary
 * search 即可
 * 時間: O(mlogn), m: row; n: column, 空間: O(1)
 */

class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (binarySearch(matrix[i], target))
            {
                return true;
            }
        }
        return false;
    }

    bool binarySearch(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};