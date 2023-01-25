#include <cmath>
#include <string>
using namespace std;

/**
 * 想法: 將其存成字串，再翻轉字串
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int reverse(int x)
    {
        bool negative = x < 0;
        string temp = to_string(abs(x));
        int i = 0, j = temp.length() - 1;
        long long int result = 0;
        while (i < j)
        {
            swap(temp[i], temp[j]);
            i++;
            j--;
        }
        for (int k = 0; k < temp.length(); k++)
        {
            cout << (temp[k] - '0');
            result = result * 10 + (temp[k] - '0');
        }
        result = negative ? -result : result;
        return result < INT_MIN || result > INT_MAX ? 0 : result;
    }
};