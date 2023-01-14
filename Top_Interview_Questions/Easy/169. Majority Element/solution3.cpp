#include <unordered_map>
#include <vector>
using namespace std;
/**
 * 參考解答: solution1 的改良版
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int half = nums.size() / 2;
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
        {
            table[nums[i]]++;
            if (table[nums[i]] > half)
            {
                return nums[i];
            }
        }
        return nums[0];
    }
};