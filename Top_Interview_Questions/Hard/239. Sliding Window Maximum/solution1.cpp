#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 每次移動 window 後，就用線性搜尋找最大值 (一共有 n-(k-1) 組) (TLE)
 * 時間: O(k*(n-(k-1))), 空間: O(1)
 */

class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.size() == k)
        {
            return {*max_element(nums.begin(), nums.end())};
        }
        int size = nums.size() - (k - 1);
        vector<int> results(size);
        for (int i = 0; i < size; i++)
        {
            // find max in range [i,i+k]
            results[i] = *max_element(nums.begin() + i, nums.begin() + i + k);
        }
        return results;
    }
};