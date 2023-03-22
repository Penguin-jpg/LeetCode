#include <stack>
#include <vector>
using namespace std;

/**
 * 參考解答: 透過 stack 來做模擬 iterator，先將 nestedList 的東西 push 到 stack
 * 中，而 flatten 的動作會實作在 hasNext (這樣其實會更加接近實際上 iterator 內所
 * 發生的事，而不是一開始就將所有資料儲存起來)
 * 時間: O(n), 空間: O(n)
 */

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
  public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        // remember to push from back to front to maintain original order
        for (int i = nestedList.size() - 1; i >= 0; i--)
        {
            nests.push(nestedList[i]);
        }
    }

    int next()
    {
        int result = nests.top().getInteger();
        nests.pop();
        return result;
    }

    bool hasNext()
    {
        while (!nests.empty())
        {
            NestedInteger nest = nests.top();
            if (nest.isInteger()) // if it is an integer, not need to flatten
            {
                return true;
            }
            // handle nested list:
            // what we are doing is that take everything out from nest and push
            // them to stack, as the iteration goes on, we will eventually get
            // those integers inside nested list, just like flatten
            nests.pop();
            vector<NestedInteger> &nestedList = nest.getList();
            for (int i = nestedList.size() - 1; i >= 0; i--)
            {
                nests.push(nestedList[i]);
            }
        }
        return false;
    }

  private:
    stack<NestedInteger> nests;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */