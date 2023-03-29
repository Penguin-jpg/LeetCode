#include <vector>
using namespace std;

/**
 * 想法: 先將兩個陣列合併，再取中位數
 * 時間: O(m+n), 空間: O(m+n)
 */

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged(nums1.size() + nums2.size());
        int i = 0, j = 0, k = 0;
        int mid = merged.size() / 2;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                merged[k] = nums1[i];
                i++;
            }
            else
            {
                merged[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < nums1.size())
        {
            merged[k] = nums1[i];
            i++, k++;
        }
        while (j < nums2.size())
        {
            merged[k] = nums2[j];
            j++, k++;
        }
        return merged.size() % 2 == 0 ? (double)(merged[mid - 1] + merged[mid]) / 2 : merged[mid];
    }
};