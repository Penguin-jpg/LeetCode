#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 想法: 先將所有的元素及其出現頻率存到一個 hash map，再用 two pointers 的方式選
 * 定兩個元素，並從 hash map 找是否存在能使三者相加為 0 的數，如果有，就將三者排
 * 序(排序是為了方便檢查是否重複且 3log3 可視為常數時間)並存到 set 內，最後再把
 * set 內的東西都存到 vector (TLE)
 * 時間: O(n^2logn), 空間: O(n)
 */

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        unordered_map<int, int> table;
        set<vector<int>> temps;
        for (int i = 0; i < nums.size(); i++)
        {
            table[nums[i]]++;
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int target = -(nums[i] + nums[j]);
                table[nums[i]]--;
                table[nums[j]]--;
                if (table.count(target) && table[nums[i]] >= 0 && table[target] > 0)
                {
                    vector<int> temp{nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    temps.insert(temp);
                }
                table[nums[i]]++;
                table[nums[j]]++;
            }
        }
        return vector<vector<int>>(temps.begin(), temps.end());
    }
};