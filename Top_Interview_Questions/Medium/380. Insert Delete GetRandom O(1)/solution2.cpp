#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 參考解答: 透過一個 hash map 和陣列來做，hash map 負責儲存 index 和檢查是否出
 * 現，陣列用來快速存取，但是若我們每次都將目前 val 對應的 index 儲存下來，當我
 * 們刪掉該 val 時，其後的所有值的 index 都要跟著減一 (我原本就是錯在這)，所以這
 * 樣做不好，更好的方式為在刪除之前先將最後一個的值複製到 val 在陣列中的位置，然
 * 後直接 pop_back，反正陣列順序並不影響這一題的解題
 * 時間: insert: O(1), remove: O(1), getRandom: average O(1), 空間: O(n)
 */

random_device randomDevice;
default_random_engine generator(randomDevice());

class RandomizedSet
{
  public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (table.count(val))
        {
            return false;
        }
        nums.push_back(val);
        // since we push every new val to back, we only need to keep track of the last index
        table[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (!table.count(val))
        {
            return false;
        }
        int last = nums.back();
        table[last] = table[val]; // copy the index of val to the last
        nums[table[val]] = last;  // move the last one to the index of val just like swappnig them
        nums.pop_back();          // pop it
        table.erase(val);
        return true;
    }

    int getRandom()
    {
        uniform_int_distribution<int> uniform(0, nums.size() - 1);
        return nums[uniform(generator)];
    }

  private:
    unordered_map<int, int> table;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */