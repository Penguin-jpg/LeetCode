#include <vector>
using namespace std;

/**
 * 想法: 元素倆倆比較，額外使用一個 vector 儲存結果，最後再 copy 到 nums1
 * 時間: O(m+n), 空間: O(m+n)
 */

class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> results(m + n);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                results[k] = nums1[i];
                i++;
            }
            else
            {
                results[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < m)
        {
            results[k] = nums1[i];
            i++;
            k++;
        }
        while (j < n)
        {
            results[k] = nums2[j];
            j++;
            k++;
        }
        nums1 = results;
    }
};