#include <vector>
using namespace std;

/**
 * 參考解答: 這是一種 dutch partitioning problem，根據題目敘述，我們可將陣列分成
 * 四個 group：red, white, blue, unclassified，由於一開始是亂的，所以全部當做
 * unclassified，透過 3 pointers (red, white, blue) 來疊代，分成以下幾種情況：
 * 1. nums[white]==0 (nums[white]=red) -> 紅色的位置錯了，所以
 *    swap(nums[white], nums[red]) -> white++, red++
 * 2. nums[white]==1 (nums[white]=white) -> 白色位置正確 -> white++
 * 3. nums[white]==2 (nums[white]=blue) -> 藍色位置錯了，所以 swap(nums[white],
 *    nums[blue]) -> blue--
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int white = 0, red = 0, blue = nums.size() - 1;
        while (white <= blue)
        {
            if (nums[white] == 0) // this position should be white but it is red
            {
                swap(nums[white], nums[red]);
                white++, red++;
            }
            else if (nums[white] == 1) // this position should be white and it is white
            {
                white++;
            }
            else // this position should be white but it is blue
            {
                swap(nums[white], nums[blue]);
                blue--;
            }
        }
    }
};
