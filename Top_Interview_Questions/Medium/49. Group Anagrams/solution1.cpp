#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 想法: 將目前的字串排序，存到 hash map，若已在 map 內就歸在同一組，否則就是新的一組
 * 時間: O(n*mlogm), n: strs長度; m: 字串長度, 空間: O(n)
 */

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> results;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            groups[strs[i]].push_back(temp);
        }
        for (auto &it : groups)
        {
            results.push_back(it.second);
        }
        return results;
    }
};