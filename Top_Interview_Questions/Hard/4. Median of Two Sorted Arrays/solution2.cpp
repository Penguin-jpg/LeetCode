#include <vector>
using namespace std;

/**
 * 參考解答: 主要概念是在不合併的前提下找到最適合的切割點，使切出的前半陣列之最
 * 大值與後半陣列之最小值相加除以二為答案(在此因為作者用了虛擬的補位法把長度都湊
 * 到 2n+1，所以兩陣列相加的長度必為偶數)，令 nums1 的長度為 m，nums2 的長度為
 * n，且不失一般性假設 m>=n，我們在 nums2 上找一個切點 k，此時 nums2 會被分為
 * [nums2[0~k], nums2[k+1~n-1]]，而因為 nums2 切出的左邊會與 nums1 切出的左邊合
 * 併成長度為 m+n 的陣列；nums2 切出的右邊穢語 nums1 切出的右邊合併成長度為 m+n
 * 的陣列，令 L1, L2 分別為 nums1 與 nums2 切出的左邊最大值，R1, R2 分別為 nums1
 * 與 nums2 切出的右邊最大值，我們只要確保 L1<=R1 && L1<=R2 &&L2<=R1 && L2<=R2，
 * 即可確定合併出的左半之最大值(左半最後一位)與右半之最小值(右半第一位)相加除以 2
 * 即為答案，在已排序的情況下可確定 L1<=R1 && L2<=R2，所以只需檢查 L1<=R2 && L2<=R1，
 * 若 L1>R2，代表 nums2 切的太過左邊，所以小的數太多，切點須往右邊靠；若 L2 > R1，
 * 代表 nums2 切得太過右邊，所以大的數太多了，切點須往左邊靠(因為最後我們並沒有
 * 真的要將 nums1, nums2 合併，所以我們無法確定 L1 與 L2 何者較大，及 R1 與 R2
 * 何者較小，所以需要取 min(L1,L2) 及 max(R1,R2) 來取得正確結果)
 *
 * (因為概念有點難簡潔描述，建議直接看以下這些網址來理解)
 * https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/2471/very-concise-o-log-min-m-n-iterative-solution-with-detailed-explanation/
 * (參考解答是根據這篇來的，3 樓留言有重點整理)
 * https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/2651020/c-solution/
 * (可以看最後一個解法註解中的例子)
 * 時間: O(log(min(m,n))), 空間: O(1)
 */

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m < n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = 0, right = n * 2;
        while (left <= right)
        {
            int mid2 = (left + right) / 2;                           // always cut the shorter array
            int mid1 = m + n - mid2;                                 // calculate the cut position of longer array
            double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2]; // greatest number of left half of nums1
            double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2]; // greatest number of left half of nums2
            double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];   // smallest number of right half of nums1
            double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];   // smallest number of left half of nums2

            if (L1 > R2) // cut position of nums2 should be more right
            {
                left = mid2 + 1;
            }
            else if (L2 > R1) // cut position should be more left
            {
                right = mid2 - 1;
            }
            else
            {
                return (max(L1, L2) + min(R1, R2)) / 2;
            }
        }
        return -1.0;
    }
};