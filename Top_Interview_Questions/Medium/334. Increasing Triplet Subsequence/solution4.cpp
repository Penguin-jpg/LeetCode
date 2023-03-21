#include <vector>
using namespace std;

/**
 * 參考解答: 由於 candidates 一定是排序的狀態(由小到大)，所以可以直接用 binary
 * search 來找需要換的候選人
 * 時間: O(n*log(k)), 空間: O(1)
 */

class Solution
{
  public:
    bool increasingTriplet(vector<int> &nums)
    {
        int k = 3;
        vector<int> candidates(k - 1, INT_MAX); // we only need to know k-1 candidates
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = lower_bound(candidates.begin(), candidates.end(), nums[i]);
            // cannot find a candidate bigger than or equal to nums[i] which
            // means the subsequence is formed
            if (iter == candidates.end())
            {
                return true;
            }
            *iter = nums[i]; // if a suitable candidate is found, change its value
        }
        return false;
    }
};