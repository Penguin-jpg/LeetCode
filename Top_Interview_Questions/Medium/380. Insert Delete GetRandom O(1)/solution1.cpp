#include <random>
#include <unordered_set>
using namespace std;

/**
 * 想法: 透過 hash set 來儲存資料，insert 和 remove 都先檢查 val 是否在 set
 * 內，getRandom 則透過 uniform distribution 的方式隨機取 0~size 的值當要取的位
 * 置，並回傳該位置的值
 * 時間: insert: O(1), remove: O(1), getRandom: average O(1), 空間: O(n)
 */

random_device randomDevice;                      // use random_device as seed
default_random_engine generator(randomDevice()); // random number generator

class RandomizedSet
{
  public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (nums.count(val))
        {
            return false;
        }
        nums.insert(val);
        return true;
    }

    bool remove(int val)
    {
        if (!nums.count(val))
        {
            return false;
        }
        nums.erase(val);
        return true;
    }

    int getRandom() // this function will not be called when there are no elements inside
    {
        uniform_int_distribution<int> uniform(0, nums.size() - 1);
        return *next(nums.begin(), uniform(generator)); // O(1)
    }

  private:
    unordered_set<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */