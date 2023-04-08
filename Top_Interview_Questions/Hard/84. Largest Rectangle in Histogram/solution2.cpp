#include <stack>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 monotonic stack 來以遞增的方式建立 stack，每次都只將比目前更大的
 * 數放入 stack，若遇到更小的數，則將 stack 頂端之值 pop 出來，並計算其面積，重
 * 複直到 stack 的 top 比目前的值更小為止，詳細解釋可參考下面連結：
 * https://leetcode.com/problems/largest-rectangle-in-histogram/solutions/995249/python-increasing-stack-explained/
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int largestRectangleArea(vector<int> &heights)
    {
        // we need this imaginary comparator to make sure we will clear the whole stack
        // consider heights=[1,2,3,4,5], we cannot clear stack and get the
        // correct answer without adding imaginary comparator 0 at the end
        heights.push_back(0);
        int maxArea = 0;
        stack<int> mono; // this stack have to maintain increasing order
        for (int i = 0; i < heights.size(); i++)
        {
            while (!mono.empty() && heights[mono.top()] >= heights[i])
            {
                int height = heights[mono.top()]; // get the height of the last index in stack
                mono.pop();                       // pop it
                // we use this height to calculate area. for example,
                // consider [1,4,2,5,6,3,2,6,6,5,2,1,3], stack=[0,2,3,4] (index), heights[i]=3 (i=5)
                // 1. heights[stack.top] > 3 -> pop -> height=heights[4]=6,
                //    width=i-top-1=5-3-1=1 (width=how many rectangles are there
                //    between i and top (only count intervals)), area=6*1=6
                // 2. heights[stack.top] > 3 -> pop -> height=heights[3]=5,
                //    width=i-top-1=5-2-1=2, area=5*2=10
                // 3. heights[stack.top] < 3 -> break loop
                // the reason why we can just use the height without check is
                // that the stack is in increasing order, so the rectangle
                // after stack.top is definitely bigger

                // count intervals if stack is not empty, otherwise, heights[i] is the smallest, we can just i as width
                int width = !mono.empty() ? i - mono.top() - 1 : i;
                maxArea = max(maxArea, width * height);
            }
            mono.push(i);
        }
        return maxArea;
    }
};