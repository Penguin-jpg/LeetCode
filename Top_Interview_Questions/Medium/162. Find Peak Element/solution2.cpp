#include <vector>
using namespace std;

/**
 * 參考解答:
 * 這一題麻煩的地方在於需要想到以下的這個證明，才有辦法寫出演算法，而且就算想到了，整體感覺起來還是挺反直覺的：
 * 反證法：
 *  - 假設若 nums[i] > nums[i-1]，則 nums[i] <= nums[i+1] for all i 皆為真
 *    -> 在 i=n 時，nums[n] <= nums[n+1] = -inf 矛盾 (因為 nums[n] 遠大於 -inf)
 *    -> 若 nums[i] > nums[i-1]，則在右邊必存在 nums[j] 使 nums[i] > nums[j], j > i
 *  - 假設若 nums[i] > nums[i+1]，則 nums[i] <= nums[i-1] for all i 皆為真
 *    -> 在 i=0 時，nums[0] <= nums[-1] = -inf 矛盾 (因為 nums[0] 遠大於 -inf)
 *    -> 若 nums[i] > nums[i+1]，則在左邊必存在 nums[j] 使 nums[i] > nums[j], j < i
 * 透過上面的證明，可以知道用 binary search 來做可分為兩種情況：
 *  1. 當 nums[mid] > nums[mid+1]，則左半邊必存在小於 nums[mid] 的數
 *  2. 當 nums[mid] > nums[mid-1]，則右半邊必存在小於 nums[mid] 的數
 * 時間: O(logn), 空間: O(1)
 */

class Solution
{
  public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1])
        {
            return 0;
        }
        else if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }
        int low = 0, high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid; // since we know that mid might be answer, we will do high=mid instead of high=mid-1
            }
        }
        return -1; // impossible to get here according to problem description
    }
};