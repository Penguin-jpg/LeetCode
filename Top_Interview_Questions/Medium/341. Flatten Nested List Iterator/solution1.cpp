#include <vector>
using namespace std;

/**
 * 想法: 透過遞迴將 nestedList 攤平，再將 flatten 後的結果另外用個陣列存起來，hasNext 就透過 index 來判斷
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
        flatten(nestedList);
    }

    void flatten(vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
            {
                nums.push_back(nestedList[i].getInteger());
            }
            else
            {
                flatten(nestedList[i].getList());
            }
        }
    }

    int next()
    {
        int result = nums[index];
        index += 1;
        return result;
    }

    bool hasNext()
    {
        return index < nums.size();
    }

  private:
    vector<int> nums;
    int index = 0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */