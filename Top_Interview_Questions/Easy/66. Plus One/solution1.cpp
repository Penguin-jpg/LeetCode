#include <vector>
using namespace std;

/**
 * 想法: 模擬直式加法，透過一個變數紀錄進位，其餘按照規則做
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry == 1)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};