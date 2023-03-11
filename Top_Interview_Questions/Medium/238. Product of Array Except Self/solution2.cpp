#include <vector>
using namespace std;

/**
 * 參考解答: 由於不能使用除法，我們要找到可以直接取得跳過 i 的乘法結果，透過兩個
 * 陣列 prefix 和 suffix 來做到，prefix[i] 代表 nums[0]*nums[1]*...*nums[j] for j<=i；
 * suffix[i] 代表 nums[j]*nums[j+1]*...*nums[n] for j>=i，觀察就可發現，跳過 i
 * 的乘積，就是 prefix[i-1] * suffix[i+1] = nums[0]*nums[1]*...*nums[i-1]*nums[i+1]*...*nums[n]
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> prefix(nums.size(), nums[0]);
        vector<int> suffix(nums.size(), nums.back());
        vector<int> results(nums.size());
        int pre = 0, suf = 0;
        for (int i = 1, j = nums.size() - 2; i < nums.size(); i++, j--)
        {
            // the logic i use here is that we know prefix[i] need to multiply
            // all nums[j] for j<=i and suffix[i] need to multiply all nums[j]
            // for j>=i. i don't want to separate it into two loops so i use two
            // loop variables i and j to loop from front and back
            prefix[i] = nums[i] * prefix[i - 1];
            suffix[j] = nums[j] * suffix[j + 1];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            pre = i > 0 ? prefix[i - 1] : 1;
            suf = i + 1 < nums.size() ? suffix[i + 1] : 1;
            results[i] = pre * suf;
        }
        return results;
    }
};