#include <vector>
using namespace std;

/**
 * 想法: 四迴圈暴力解，會比 backtracking 快，但還是會 TLE
 * 時間: O(n^4), 空間: O(1)
 */

class Solution
{
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int counter = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                for (int k = 0; k < nums3.size(); k++)
                {
                    for (int l = 0; l < nums4.size(); l++)
                    {
                        if (nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0)
                        {
                            counter++;
                        }
                    }
                }
            }
        }
        return counter;
    }
};