#include <algorithm>
#include <vector>
using namespace std;

/**
 * 參考解答: 先把 nums 排序，就可以利用這點做 O(n^2) 的 three pointers，每次取
 * left=i+1, right=n-1 開始逼近，由於排序過，所以若相加小於 0，可以確定是 left
 * 太小；相加大於 0，可以確定是 right 太大，再把所有與該組重複的 triplet 都跳掉即可
 * 時間: O(n^2), 空間: O(n)
 */

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int sum = 0;
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            // skip the same nums[i] (start from i=1 because the former
            // nums[i-1] might need to use nums[i])
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                {
                    left++;
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    vector<int> triplet({nums[i], nums[left], nums[right]});
                    results.push_back(triplet);
                    while (left < right && nums[left] == triplet[1]) // skip the same nums[left]
                    {
                        left++;
                    }
                    while (right > left && nums[right] == triplet[2]) // skip the same nums[right]
                    {
                        right--;
                    }
                }
            }
        }
        return results;
    }
};