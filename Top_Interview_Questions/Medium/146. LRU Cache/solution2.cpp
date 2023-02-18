#include <list>
#include <unordered_map>
using namespace std;

/**
 * 參考解答: 為了將 put 壓到 O(1)，代表我們必須持續追蹤最近最少用的是誰，目前看
 * 到大部分的方式都是用 doubly linked list 然後儲存他的 iterator，list 最前面的元素是最近剛用
 * 到的；最後面的元素是最近最少用的到
 * 時間: get: O(1), put: O(1), 空間: O(n)
 */

class LRUCache
{
  public:
    LRUCache(int capacity) : capacity(capacity)
    {
    }

    int get(int key)
    {
        if (!cache.count(key))
        {
            return -1;
        }
        // this line means take the element of lru which cache[key](the iterator) points at and insert it to lru.begin()
        // since we want to push the most recently used element to the front
        lru.splice(lru.begin(), lru, cache[key]);
        return cache[key]->second;
    }

    void put(int key, int value)
    {
        if (cache.count(key))
        {
            lru.splice(lru.begin(), lru, cache[key]); // push the most recently used element to the front
            cache[key]->second = value;               // update value
            return;
        }
        else if (lru.size() == capacity) // lru is full
        {
            cache.erase(lru.back().first); // erase the least used element (the back of lru)
            lru.pop_back();                // pop the last element
        }
        lru.push_front({key, value}); // push the new element to the front
        cache[key] = lru.begin();     // store its corresponding iterator
    }

  private:
    int capacity;
    list<pair<int, int>> lru;                                 // store key and value
    unordered_map<int, list<pair<int, int>>::iterator> cache; // key and its corresponding iterator in lru
};