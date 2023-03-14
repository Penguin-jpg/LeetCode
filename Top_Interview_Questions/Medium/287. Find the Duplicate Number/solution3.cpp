#include <vector>
using namespace std;

/**
 * 參考解答: 用 binary search 解，假設每次都去 mid，檢查有幾個數是小於等於 mid，
 * 如果數量超過 mid，則搜尋左半，否則搜尋右半
 * 證明：
 * 令 count 是 [1,mid] 的元素數量
 * 1. 若 count>mid：
 *    在 mid 大小的空間內要塞入超過 mid 的數量 -> 根據鴿洞原理，在範圍[1,mid]必定會有重複的數
 * 2. 若 count<=mid：
 *    在範圍 [mid+1,n] 內有 n+1-count 個元素，也就是至少有 n+1-mid 個元素塞入
 *    n-mid 大小的空間 -> 根據鴿洞原理，在範圍[mid+1,n]必定有重複的數
 * 更詳細解說可看下列連結的第一則留言：
 * https://leetcode.com/problems/find-the-duplicate-number/solutions/72844/two-solutions-with-explanation-o-nlog-n-and-o-n-time-o-1-space-without-changing-the-input-array/
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int counter = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] <= mid)
                {
                    counter++;
                }
            }
            if (counter > mid)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};