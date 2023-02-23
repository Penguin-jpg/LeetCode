#include <vector>
using namespace std;

/**
 * 想法: 找出有多少個 10 即為答案，也就是能湊出多少個 2*5，由於 2 有很多個，所以
 * 其實只要找能湊出多少個 5 就好 (要注意當目前的數為 5^x, x>1 時，對應的 5 的數
 * 量是 x，不是 1)
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int trailingZeroes(int n)
    {
        int counter = 0;
        vector<pair<int, int>> exp;
        for (int i = 5, j = 1; i <= n; i *= 5, j++)
        {
            exp.push_back(make_pair(i, j));
        }
        for (int i = 5; i <= n; i += 5)
        {
            for (int j = exp.size() - 1; j >= 0; j--)
            {
                if (i % exp[j].first == 0) // decide the amount to add
                {
                    counter += exp[j].second;
                    break;
                }
            }
        }
        return counter;
    }
};