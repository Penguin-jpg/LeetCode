#include <queue>
using namespace std;

/**
 * 參考解答: 由於我們希望能用 O(1) 找到中位數，所以必須要用 O(1) 存取特定元素的
 * 資料結構，可以將整個 nums 拆分成兩個 heap，一個 max-heap 存 nums 中較小的那一
 * 半數字；一個 min-heap 存 nums 中教大的那一半數字，當我們要找中位數時，若
 * max-heap 和 min-heap 大小相同，代表有偶數個元素，就取 max-heap 和 min-heap 的
 * top 再相加除以二；否則就取 max-heap 的 top，詳細可看以下連結：
 * https://leetcode.com/problems/find-median-from-data-stream/solutions/1330646/c-java-python-minheap-maxheap-solution-picture-explain-clean-concise/
 * 時間: 插入: O(logn); 找中位數: O(1), 空間: O(n)
 */

class MedianFinder
{
  public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // the goal is to keep sizes of two heaps balance
        maxHeap.push(num); // first push num to max-heap
        // since num might belong to the larger part, we pop the top from
        // max-heap and give it to min-heap to maintain the balance
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        // same reason for this check
        if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        // size is balanced means that there are even number of elements
        // if it is not balanced, means that median is the top of max-heap
        return maxHeap.size() == minHeap.size() ? (maxHeap.top() + minHeap.top()) / 2.0 : maxHeap.top();
    }

  private:
    priority_queue<int> maxHeap;                            // store the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // store the larger half
};