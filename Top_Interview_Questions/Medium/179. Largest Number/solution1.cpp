#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答：其實不需要想這麼多，只要 compare 的時候 a+b>b+a，就排成 a,b，否則就
 * 排成 b,a，還要記得避免 leading zero
 * 時間: O(nlogn), 空間: O(n)
 */

bool cmp(const string &a, const string &b)
{
    return a + b > b + a;
}

class Solution
{
  public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> strs(nums.size());
        string result = "";
        for (int i = 0; i < nums.size(); i++)
        {
            strs[i] = to_string(nums[i]);
        }
        sort(strs.begin(), strs.end(), cmp);
        for (int i = 0; i < strs.size(); i++)
        {
            result += strs[i];
        }
        while (result[0] == '0' && result.length() > 1) // prevent leading zero
        {
            result.erase(result.begin());
        }
        return result;
    }
};