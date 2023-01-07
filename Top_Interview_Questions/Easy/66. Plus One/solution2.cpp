#include <vector>
using namespace std;

/**
 * 參考解答: 加入 early return，當確定沒有進位時，其實就能直接回傳了
 */

class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else // if current digit is not 9, we can safely + 1
            {
                digits[i]++;
                return digits;
            }
        }
        // if we are here, it means the first digit + 1 = 10, so insert 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};