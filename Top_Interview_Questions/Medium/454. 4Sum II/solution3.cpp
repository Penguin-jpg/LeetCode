#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 參考解答: 先將 nums4 的值存到 hash map 內，就可以減少一層迴圈，但還是會 TLE
 * 時間: O(n^3), 空間: O(n)
 */

class Solution
{
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> table; // num4 and frequency
        int counter = 0;
        for (int i = 0; i < nums4.size(); i++)
        {
            table[nums4[i]]++;
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                for (int k = 0; k < nums3.size(); k++)
                {
                    counter += table[0 - nums1[i] - nums2[j] - nums3[k]];
                }
            }
        }
        return counter;
    }
};