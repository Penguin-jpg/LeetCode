#include <stack>
#include <utility>
using namespace std;

/**
 * 參考解答: 這題的概念其實很簡單，先從為什麼題目要選擇使用 stack 來做這項任務，
 * 因為 stack 會一直往上疊，上面的層被抽走也不會影響下面的層，每層之間的關係相對
 * 於其他資料結構更加獨立，例如：stack=[1,5,-1,6,7](越右邊越上層)，對於 "7" 來
 * 說，他所看到的目前最小值為 "-1"，而在 "-1" 之前的元素所看到的目前最小值為
 * "1"，所以不論是 "7" 被抽走還是 "-1" 被抽走，都不影響其找"目前"最小值的判斷
 *
 * 為了能夠 O(1) 取得目前最小值，我們把每一個元素都存成 pair(元素, 目前最小值)，
 * 並在 push 時判斷目前的值是否比先前的最小值更小即可
 * 時間: O(n), 空間: O(n)
 */

class MinStack
{
  public:
    MinStack()
    {
    }

    void push(int val)
    {
        // if nums is empty, then val is current min
        // otherwise, compare val and the current min and choose the smaller one
        int currentMin = nums.empty() ? val : val < nums.top().second ? val : nums.top().second;
        nums.push(make_pair(val, currentMin));
    }

    void pop()
    {
        nums.pop();
    }

    int top()
    {
        return nums.top().first;
    }

    int getMin()
    {
        return nums.top().second;
    }

  private:
    stack<pair<int, int>> nums;
};

// 如果面試官不接受直接使用 STL stack，可以改用 vector(雖然 STL stack 就是特殊設計過的 vector)
class MinStack
{
  public:
    MinStack()
    {
    }

    void push(int val)
    {
        int currentMin = stack.empty() ? val : val < stack.back().second ? val : stack.back().second;
        stack.push_back(make_pair(val, currentMin));
    }

    void pop()
    {
        stack.pop_back();
    }

    int top()
    {
        return stack.back().first;
    }

    int getMin()
    {
        return stack.back().second;
    }

  private:
    vector<pair<int, int>> stack;
};