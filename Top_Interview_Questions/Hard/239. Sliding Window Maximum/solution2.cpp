#include <set>
#include <vector>
using namespace std;

/**
 * 想法: 用 max-heap，保持 heap 內有 k 個元素，然而移除時不是要刪掉最大的元素，
 * 而是第一個加進來的元素，所以改用 multiset 實作
 * 時間: O(nlogk), 空間: O(k)
 */

class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // push first k elements
        multiset<int> maxHeap(nums.begin(), nums.begin() + k);
        vector<int> results;
        int firstElement = 0;
        int index = k; // start from index k
        while (maxHeap.size() == k)
        {
            results.push_back(*maxHeap.rbegin());            // push the biggest element
            maxHeap.erase(maxHeap.find(nums[firstElement])); // delete first element
            // only insert new element when index < nums.size()
            if (index < nums.size())
            {
                maxHeap.insert(nums[index]);
            }
            firstElement++;
            index++;
        }
        return results;
    }
};