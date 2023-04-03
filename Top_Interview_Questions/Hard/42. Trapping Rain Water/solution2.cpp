#include <vector>
using namespace std;

/**
 * 參考解答: 我們可以透過 two pointers 來模擬 solution1，先假設
 * maxLeft=height[0], maxRight=height[n-1], left=0, right=n-1，
 * 若 maxLeft<maxRight，代表高度要以左邊為準，這時再檢查若
 * height[left]>maxLeft，就把 maxLeft 更新成 height[i]，而 height[i]<=maxLeft 就
 * 是可以裝水；maxRight<=maxLeft 同理，就換成檢查 height[right] 和 maxRight
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int result = 0, left = 0, right = height.size() - 1;
        int maxLeft = height[0], maxRight = height.back();
        while (left <= right)
        {
            if (maxLeft < maxRight) // water level is based on left side
            {
                if (height[left] > maxLeft) // need to update maxLeft
                {
                    maxLeft = height[left];
                }
                else
                {
                    result += maxLeft - height[left];
                }
                left++;
            }
            else // water level is based on right side
            {
                if (height[right] > maxRight) // need to update maxRight
                {
                    maxRight = height[right];
                }
                else
                {
                    result += maxRight - height[right];
                }
                right--;
            }
        }
        return result;
    }
};