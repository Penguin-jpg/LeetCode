#include <algorithm>
#include <vector>
using namespace std;

/**
 * 參考解答: 透過 STL 的 unique 去除重複元素
 */

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};