#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 想法: 先用 hash map 把 nums1 所有出現數字的次數記起來，再跑一次 nums2，如果次
 * 數 > 0，就抵銷一次並記錄起來
 * 時間: O(n+m), n: nums1長度; m: nums2長度, 空間: O(n)
 */

class Solution
{
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> table;
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++)
        {
            table[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (table.count(nums2[i]) && table[nums2[i]] > 0)
            {
                table[nums2[i]]--;
                result.push_back(nums2[i]);
            }
        }
        return result;
    }
};