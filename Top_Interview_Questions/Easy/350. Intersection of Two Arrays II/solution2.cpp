#include <vector>
using namespace std;

/**
 * 參考解答: 先排序，再做 two pointers
 * 時間: O(nlogn+mlogm), 空間: O(1)
 */

class Solution
{
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) // need to find bigger element in nums1
            {
                i++;
            }
            else if (nums2[j] < nums1[i]) // need to find bigger element in nums2
            {
                j++;
            }
        }
        return result;
    }
};