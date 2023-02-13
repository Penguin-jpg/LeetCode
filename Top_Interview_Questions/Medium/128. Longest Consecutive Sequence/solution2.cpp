#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 hash map 解，table[i] 代表 i 可以形成的最長連續子序列長度，主要
 * 可以分成以下四種情況：
 *      1. m[i-1] not in table and m[i+1] not in table:
 *         找不到 i-1 或 i+1，代表不可能形成連續子序列 -> 長度 1
 *      2. m[i+1] in table:
 *         i+1 在 table 內，可以形成 i,i+1 的連續子序列
 *      3. m[i-1] in table:
 *         i-1 在 table 內，可以形成 i-1,i 的連續子序列
 *      4. m[i+1] in table and m[i-1] in table:
 *         i-1 跟 i+1 都在 table 內，可以形成 i-1,i,i+1 的連續子序列
 * 透過以上幾種情況就可延伸出所有的連續子序列
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> table;
        int maxLength = 0, currentLength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (table[num] != 0) // table[num] already calculated
            {
                continue;
            }
            else if (!table.count(num - 1) && !table.count(num + 1)) // num-1 and num+1 not in table
            {
                currentLength = 1;
                table[num] = currentLength;
            }
            else if (!table.count(num - 1)) // num-1 not in table but num+1 in table
            {
                // table[num+1]+1 to extend the max length of num+1 by 1
                // table[num] is the left boundary
                // table[num+table[num+1]] is the right boundary
                // e.g. 3,4,5,6 -> table[3]=4(left boundary), table[6]=4(right boundary)
                currentLength = table[num + 1] + 1;
                table[num] = currentLength;
                table[num + table[num + 1]] = currentLength;
            }
            else if (!table.count(num + 1)) // num-1 in table but num+1 not in table
            {
                // same logic for num-1
                currentLength = table[num - 1] + 1;
                table[num] = currentLength;
                table[num - table[num - 1]] = currentLength;
            }
            else // num-1 in table and num+1 in table
            {
                currentLength = table[num - 1] + table[num + 1] + 1;
                table[num] = currentLength;
                table[num - table[num - 1]] = currentLength;
                table[num + table[num + 1]] = currentLength;
            }
            maxLength = max(maxLength, currentLength);
        }
        return maxLength;
    }
};