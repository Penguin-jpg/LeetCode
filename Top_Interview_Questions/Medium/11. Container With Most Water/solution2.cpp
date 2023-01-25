#include <vector>
using namespace std;

/**
 * 參考解答: 用 greedy 和 two pointers，由於需要考慮寬度，所以從寬度最大的兩側開
 * 始，並逐步限縮範圍，但由於較長的邊必須配合較短的邊，所以若把較長的邊換成較短
 * 的並不會有任何好處，但把較短的邊換成較長的可能會得到新的最大值
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1, maxValue = 0;
        while (left < right)
        {
            maxValue = max(maxValue, min(height[left], height[right]) * (right - left));
            // replace the shorter one to see if we will get a longer line
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxValue;
    }
};