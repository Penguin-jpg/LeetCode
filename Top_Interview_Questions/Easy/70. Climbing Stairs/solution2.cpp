#include <unordered_map>
using namespace std;

/**
 * 想法: 用 DP memo法
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int climbStairs(int n)
    {
        unordered_map<int, int> memo;
        return helper(n, memo);
    }

    int helper(int n, unordered_map<int, int> &memo)
    {
        if (n < 0)
        {
            return 0;
        }
        else if (n <= 1)
        {
            return 1;
        }
        else if (memo.count(n))
        {
            return memo[n];
        }
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }
};