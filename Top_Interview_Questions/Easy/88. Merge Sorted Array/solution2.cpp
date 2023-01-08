#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 把 nums2 通通放到 nums1 後面，再全部一起排序
 * 時間: O((m+n)log(m+n)), 空間: O(1)
 */

class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i + m] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};