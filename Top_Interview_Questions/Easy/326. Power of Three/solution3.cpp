/**
 * 參考解答: 直接取 int 中 3 可以得到的最大指數，也就是 3^19，並用其做檢查
 * 時間: O(1), 空間: O(1)
 */

class Solution
{
  public:
    bool isPowerOfThree(int n)
    {
        int maxNum = 1162261467; // 3^19
        return n > 0 && maxNum % n == 0;
    }
};