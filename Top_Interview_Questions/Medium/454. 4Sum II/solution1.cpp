#include <vector>
using namespace std;

/**
 * 想法: 用 backtracking 將所有可能找出 (TLE)
 * 時間: O(4*2^n), 空間: O(n)
 */

class Solution
{
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int counter = 0;
        vector<int> temp;
        vector<vector<int>> nums({nums1, nums2, nums3, nums4});
        backtracking(nums, 0, temp, counter);
        return counter;
    }

    void backtracking(vector<vector<int>> &nums, int index, vector<int> &temp, int &counter)
    {
        if (index >= 4)
        {
            int result = 0;
            for (int i = 0; i < temp.size(); i++)
            {
                result += nums[i][temp[i]];
            }
            if (result == 0)
            {
                counter++;
            }
            return;
        }
        for (int i = 0; i < nums[index].size(); i++)
        {
            temp.push_back(i);
            backtracking(nums, index + 1, temp, counter);
            temp.pop_back();
        }
    }
};