#include <vector>
using namespace std;

/**
 * 參考解答: 透過 XOR 消除相同值的特性，最後留下的應該就是缺少的數
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int missingNumber(vector<int> &nums)
    {
        int missingNum = 0;
        for (int i = 0; i < nums.size() + 1; i++)
        {
            missingNum ^= i; // now missingNum = 0^1^2...^n
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // all existing number will be turned to zero by applying XOR,
            // so the last number left is the answer
            missingNum ^= nums[i];
        }
        return missingNum;
    }
};