#include <deque>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 deque 來做，詳細過程看程式註解或下面連結的一樓連言
 * https://leetcode.com/problems/sliding-window-maximum/solutions/65898/clean-c-o-n-solution-using-a-deque/
 * 時間: O(n), 空間: O(k)
 */

class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq; // store index in range [i-k, i]
        vector<int> results;
        for (int right = 0; right < nums.size(); right++)
        {
            if (dq.front() == right - k) // element with this index is out of window
            {
                dq.pop_front();
            }
            // remove elements that are smaller than the element to be added
            // we do this because if elements in range [i, i+k] (i+k is the
            // "right" we are using) are smaller than nums[i+k], they are
            // definitely not candidates for the max value
            // e.g. [1,3,-1,-3,5,3,6,7], k=3, right=4, dq=[1,2,3]
            // after removing front, dq=[2,3] -> [-1,-3]
            // next window should be [-1,-3,5] -> since -1,-3 is smaller than 5,
            // there are no way they will be max (this is still true for every
            // window after this one)
            while (!dq.empty() && nums[dq.back()] < nums[right])
            {
                dq.pop_back();
            }
            dq.push_back(right);    // push new element
            if (right + 1 - k >= 0) // we can start to find max at index k since window is constructed
            {
                results.push_back(nums[dq.front()]); // the front should be the biggest
            }
        }
        return results;
    }
};