#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 透過一個陣列儲存資料，並在需要計算中位數先排序，再找中位數 (TLE)
 * 時間: 插入: O(1); 找中位數: O(nlogn), 空間: O(n)
 */

class MedianFinder
{
  public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        sorted = false;
        nums.push_back(num);
    }

    double findMedian()
    {
        if (!sorted)
        {
            sort(nums.begin(), nums.end());
            sorted = true;
        }
        return nums.size() % 2 != 0 ? nums[nums.size() / 2] : (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0;
    }

  private:
    vector<int> nums;
    bool sorted = false;
};