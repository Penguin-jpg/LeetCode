#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 參考解答: 首先將 nums 存到 set 內，好處是可以把重複元素的問題去掉，也可以很快
 * 的存取，目標在尋找最大的 i,i+1,i+2,...，當目前為 i 時，先檢查 i-1 是否在 nums
 * 內，若 i-1 存在於 nums 內，則由 i 開始的連續子序列就不可能為最長，若 i-1 不在
 * nums 內，則找 i+1,i+2,...,j 是否在 nums 內，若存在，則該長度則為 j-i+1
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> elements(nums.begin(), nums.end());
        int maxLength = 0;
        for (auto &element : elements)
        {
            if (!elements.count(element - 1))
            {
                int end = element + 1;
                while (elements.count(end))
                {
                    end++;
                }
                maxLength = max(maxLength, end - element);
            }
        }
        return maxLength;
    }
};