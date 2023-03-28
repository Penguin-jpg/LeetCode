#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 參考解答: 為了要從 solution3 再拔掉一層迴圈，我們將 nums3 也存到 hash map 內
 * 時間: O(n^2), 空間: O(n)
 */

class Solution
{
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> table; // sum of num3 and num4 and their frequency
        int counter = 0;
        for (int i = 0; i < nums3.size(); i++)
        {
            for (int j = 0; j < nums4.size(); j++)
            {
                table[nums3[i] + nums4[j]]++;
            }
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                counter += table[0 - nums1[i] - nums2[j]];
            }
        }
        return counter;
    }
};