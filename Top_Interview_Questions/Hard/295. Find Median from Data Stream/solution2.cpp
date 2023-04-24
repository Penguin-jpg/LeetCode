#include <set>
using namespace std;

/**
 * 想法: 改成插入時就會排序的資料結構來節省時間，這裡我使用 c++ 的 multiset (TLE)
 * 時間: 插入: O(logn); 找中位數: O(logn), 空間: O(n)
 */

class MedianFinder
{
  public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        nums.insert(num);
    }

    double findMedian()
    {
        int size = nums.size();
        return size % 2 != 0 ? *(next(nums.begin(), size / 2))
                             : (*(next(nums.begin(), size / 2 - 1)) + *(next(nums.begin(), size / 2))) / 2.0;
    }

  private:
    multiset<int> nums;
};