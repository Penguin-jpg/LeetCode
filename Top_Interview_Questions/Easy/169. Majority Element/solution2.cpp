#include <vector>
using namespace std;
/**
 * 想法: 用摩爾投票演算法找眾數，其概念類似透過消耗戰決定最後活著的人
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int counter = 0;
        int winner = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // change winner if counter = 0
            if (counter == 0)
            {
                winner = nums[i];
                counter++;
            }
            else if (nums[i] != winner) // if find other with different opinion, counter--
            {
                counter--;
            }
            else // if find other with same opinion, counter++
            {
                counter++;
            }
        }
        return winner;
    }
};