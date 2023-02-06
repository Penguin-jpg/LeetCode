#include <cmath>
#include <vector>
using namespace std;

/**
 * 想法: 用 bit operation 來做，從 1 疊代到 2^n-1，每個數字都用一個 counter 記錄
 * 目前是第幾個數字，若目前這個 bit 取 AND 1 後不為 0，則將目前 counter 對應的值
 * 放到 subset 內，重複直到結束
 * 時間: O(2^n), 空間: O(n)
 */

class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.size() == 1 && nums[0] == 0)
        {
            return {{}, {0}};
        }
        int size = pow(2, nums.size());
        int temp = 0, counter = 1;
        vector<vector<int>> results(size);
        for (int i = 0; i < size; i++)
        {
            temp = i, counter = 0;
            vector<int> subset;
            while (temp > 0)
            {
                if (temp & 1)
                {
                    subset.push_back(nums[counter]);
                }
                temp >>= 1;
                counter++;
            }
            results[i] = subset;
        }
        return results;
    }
};