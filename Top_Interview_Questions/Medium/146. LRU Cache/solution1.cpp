#include <unordered_map>
using namespace std;

/**
 * 想法: 用 hash map 當 cache，get 就用 key 直接找，會透過一個 counter 紀錄目前
 * 最大的使用次數，使用 put 時先檢查目前 hash map 的大小有沒有超過 capacity，若
 * 沒有就直接加入，並更新其使用度，若超過的話就將目前使用度最低的那個替換掉 (TLE)
 * 時間: get: O(1), put: O(n), 空間: O(n)
 */

class LRUCache
{
  public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        int value = cache.count(key) ? cache[key].first : -1;
        if (value != -1)
        {
            cache[key].second = counter;
            counter++;
        }
        // cout << "get cache: \n";
        // for (auto &it : cache)
        // {
        //     cout << "key: " << it.first << " (value, counter): " << it.second.first << ", " << it.second.second <<
        //     endl;
        // }
        return value;
    }

    void put(int key, int value)
    {
        if (!cache.count(key) && cache.size() == capacity)
        {
            int leastUsed = -1, minValue = INT_MAX;
            for (auto &it : cache)
            {
                if (it.second.second < minValue)
                {
                    leastUsed = it.first;
                    minValue = it.second.second;
                    // cout << "leastUsed: " << leastUsed << endl;
                }
            }
            cache.erase(leastUsed);
        }
        cache[key] = make_pair(value, counter);
        counter++;
        // cout << "put cache: \n";
        // for (auto &it : cache)
        // {
        //     cout << "key: " << it.first << " (value, counter): " << it.second.first << ", " << it.second.second <<
        //     endl;
        // }
    }

  private:
    int capacity;
    int counter = 1;
    unordered_map<int, pair<int, int>> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */