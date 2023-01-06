#include <vector>
using namespace std;

/**
 * 想法: 透過一個參數紀錄上一個重複的數字以及一個參數紀錄接下來的交換位置，
 * 當遇到未出現過的數字，就更新重複數字並交換至目標位置，最後回傳不重複的數字數量
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int duplicate = nums[0];
        int pos = 1;
        int counter = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != duplicate)
            {
                counter++;
                duplicate = nums[i];
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
        return counter;
    }
};