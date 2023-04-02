#include <vector>
using namespace std;

/**
 * 參考解答: 首先要觀察出答案只可能介於 [1,n+1] (可以試著舉幾個例子，就會發
 * 現這個必成立)，接下來為了符合題目要求的常數空間複雜度，我們必須把資訊記錄在
 * nums 並同時保留其原本的數值，也就是我們的目標是將 nums[i] 都放到
 * nums[nums[i]-1] 之上，所以接下來 iterate 整個陣列，只要 nums[i]<0 或 nums[i]>n
 * 的數都不用管，而在範圍內且不在位置上的數都要將其換到正確位置上，如此一來，當
 * 整個迴圈結束後，所有範圍內的數都應該會在自己的對應位置(數字 a 會在
 * nums[a-1])，我們只要把 a!=nums[a-1] 的數找出來即為答案，若都找不到，代表答案
 * 是 n+1
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        int i = 0, n = nums.size();
        while (i < n) // after this loop, every num in range should be at correct position
        {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]); // swap "a" to nums[a-1]
            }
            else
            {
                i++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i != nums[i - 1])
            {
                return i;
            }
        }
        return n + 1; // if not in range [1,n]
    }
};