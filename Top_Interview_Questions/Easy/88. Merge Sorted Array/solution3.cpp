#include <vector>
using namespace std;

/**
 * 參考解答: 把整個問題是為反向排序，用 i,j,k 分別指向 nums1 數字結尾、nums2 數
 * 字結尾、nums1 陣列結尾，並用基本的 list merge 方法去做
 * 時間: O(m+n), 空間: O(1)
 */

class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while (j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};