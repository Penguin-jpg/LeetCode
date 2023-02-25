#include <vector>
using namespace std;

/**
 * 想法: 雖然 solution2 會超時，但提供了我們一個很好的思路，可以觀察到一次推
 * 動一格時，實際讓就是前 n-1 格往右推，第 n 格變到第 0 格，現在需要推 k 格，所
 * 以就是前 n-k 格往右推，第 n-k 格變到第 0 格，第 n-k-1 格變到第 1 格，...，第
 * n 格變到第 k 格 (目前沒看到有人這樣解，但我覺得透過這個解法可以更加瞭解 solution4)
 * 時間: O(k*n), k=k%n, 空間: O(k)
 */

class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        vector<int> temp(k);
        for (int i = 0; i < k; i++)
        {
            temp[i] = nums[n - k + i];
        }
        for (int i = n - 1; i - k >= 0; i--)
        {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }
    }
};