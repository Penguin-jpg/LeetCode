#include <vector>
using namespace std;

/**
 * 參考解答: 觀察可發現，若要能夠裝水，則左邊及右邊均要存在比自己更高的牆，所以我
 * 們可以先把對所有 i 來說左邊最高的牆 maxLeft[i] 及右邊最高的牆 maxRight[i] 都先
 * 找出來，計算時直接取 min(maxLeft[i], maxRight[i])，但要注意的是雖然
 * maxLeft[i] 和 maxRight[i] 是對 height[i] 來說最大的左邊及右邊，但並不代表他們
 * 比 height[i] 還要更高，所以我們必須檢查算出的水位是否 >= height[i]，是的話才
 * 將該水位扣掉 height[i] 後加入答案
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int result = 0;
        vector<int> maxLeft(height.size(), 0), maxRight(height.size(), 0);
        for (int i = 1; i < height.size(); i++)
        {
            maxLeft[i] = max(height[i - 1], maxLeft[i - 1]);
        }
        for (int i = height.size() - 2; i >= 0; i--)
        {
            maxRight[i] = max(height[i + 1], maxRight[i + 1]);
        }
        for (int i = 0; i < height.size(); i++)
        {
            int level = min(maxLeft[i], maxRight[i]);
            // level < height[i] means that height[i] will be taller than the
            // water level, so no water trapped
            result += level >= height[i] ? level - height[i] : 0;
        }
        return result;
    }
};