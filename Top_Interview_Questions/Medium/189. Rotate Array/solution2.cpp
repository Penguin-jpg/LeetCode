#include <vector>
using namespace std;

/**
 * 參考解答: 一次將陣列往右推 1 格，推 k 次 (TLE)
 * 時間: O(k*n), k=k%n, 空間: O(1)
 */

class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        for (int i = 0; i < k; i++)
        {
            int temp = nums[n - 1]; // store the last element
            // move the last n-1 elements by 1
            for (int j = n - 1; j > 0; j--)
            {
                nums[j] = nums[j - 1];
            }
            // the last element will be pushed to index 0
            nums[0] = temp;
        }
    }
};