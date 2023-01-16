#include <unordered_map>
using namespace std;

/**
 * 想法: 寫個迴圈把各個位數拆開並平方相加，將出現過的數字用 hash map 存起來，如
 * 果重複回到已出現過的數字，則代表不是 happy number，如果目前數字為 1，則為
 * happy number
 * 時間: O(n), n: 所需的計算次數, 空間: O(n)
 */

class Solution
{
  public:
    bool isHappy(int n)
    {
        unordered_map<int, bool> table;
        int sum = 0;
        int digit = 0;
        while (sum != 1)
        {
            if (table.count(sum))
            {
                return false;
            }
            table[sum] = true;
            sum = 0;
            while (n > 0)
            {
                digit = n % 10;
                n /= 10;
                sum += digit * digit;
            }
            n = sum;
        }
        return true;
    }
};