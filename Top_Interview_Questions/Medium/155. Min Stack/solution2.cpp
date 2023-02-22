#include <utility>
#include <vector>
using namespace std;

/**
 * 參考解答: 如果面試官希望實作一個 stack (不能用 STL vector 或 STL stack)
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
        int currentMin = currentPos == -1 ? val : val < pairs[currentPos].second ? val : pairs[currentPos].second;
        currentPos++;
        pairs[currentPos] = make_pair(val, currentMin);
    }

    void pop()
    {
        currentPos--;
    }

    int top()
    {
        return pairs[currentPos].first;
    }

    int getMin()
    {
        return pairs[currentPos].second;
    }

  private:
    pair<int, int> pairs[100000];
    int currentPos = -1;
};