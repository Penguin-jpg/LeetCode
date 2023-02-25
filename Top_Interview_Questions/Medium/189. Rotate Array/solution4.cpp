#include <algorithm>
#include <vector>
using namespace std;

/**
 * 參考解答: 透過 solution3 能觀察到另一個規律，我們可以把陣列分成前 n-k 個元素
 * (稱為 sub1)及後面 k 個元素(稱為 sub2)構成的兩個子陣列，因為我們知道旋轉完時
 * 順序應該為 sub2,sub1，但若直接 reverse，會發現元素的順序全都反過來了，所以應
 * 該要先對 sub1 和 sub2 做 reverse，最後在整個 reverse 一次，順序就會正常
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.begin() + n - k); // reverse [0:n-k-1]
        reverse(nums.begin() + n - k, nums.end());   // reverse [n-k:n-1]
        reverse(nums.begin(), nums.end());           // reverse whole array
    }
};