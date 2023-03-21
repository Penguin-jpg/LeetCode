#include <utility>
using namespace std;

/**
 * 參考解答: 這一題可以用 greedy 解，直觀上可以這樣理解，我們透過一個變數 c1 記
 * 錄目前最適合的最小候選人以及一個變數 c2 記錄目前最適合的第二大候選人，而我們在
 * 跑迴圈時會隨時將最小的值更新到 c1，第二大的值更新到 c2，若這時出現一個值大於 c1
 * 且大於 c2，則 triplet {c1,c2,x} 自動成立
 * (之前有想到類似的方式，但被在想反例時覺得行不通就沒寫了，然而實際上是可解的，
 * 可以參考以下這個例子： [2,3,0,6]
 * 雖然在更新後，c1 會跑到 0，而不是理論上的正解 2，但實際上根本不影響，因為 c1
 * 的涵義是"目前最適合的最小候選人"，而不是最終候選人，也就是只要 c1 有變動過(脫離預設值)，
 * 就代表曾經出現過一個數小於 c2 且大於現在的 c1，也就是儘管我們沒有記錄著該數，
 * 我們仍然可以利用這個資訊來確定能不能組合出正確的 triplet)
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    bool increasingTriplet(vector<int> &nums)
    {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= c1) // smaller than c1
            {
                c1 = nums[i];
            }
            else if (nums[i] <= c2) // larger than c1 but smaller than c2
            {
                c2 = nums[i];
            }
            else // exist a number larger than c1 and c2 -> triplet {c1,c2,nums[i]} formed
            {
                return true;
            }
        }
        return false;
    }
};