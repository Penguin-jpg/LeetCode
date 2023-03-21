#include <vector>
using namespace std;

/**
 * 參考解答: 更 general 的方式來寫 solution2，可延伸到長度 k 的 increasing subsequence
 * 時間: O(n*k), 空間: O(1)
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
            for (int j = 0; j < candidates.size(); j++)
            {
                if (nums[i] <= candidates[j])
                {
                    candidates[j] = nums[i];
                    break; // use break to simulate the effect of "else if"
                }
                else if (j == k - 2) // if there exists a number bigger than the last candidate, the subsequence formed
                {
                    return true;
                }
            }
        }
        return false;
    }
};