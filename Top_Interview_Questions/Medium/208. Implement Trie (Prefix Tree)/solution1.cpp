#include <string>
using namespace std;

/**
 * 想法: Trie 的概念就是把 26 個字母都建立一個 Trie 存起來，稱為 children，以及
 * 使用一個 bool 紀錄單字目前的 Trie 是否為單字結尾，稱為 endOfWord，每個
 * children 又會再有 children，如此一來就能把每個單字都建立一條對應的 Trie
 * insert 的方式是把每個字的字元依序放入 child1->child2->...，直到整個字都放完，
 * 把最後的 child 的 endOfWord 改為 true
 * search 的方式是把按照每個字元找 child1->child2->...，如果在某個 child
 * 內找不到，就是 false，當全部跑完，要確定該 child 是 endOfWord 才代表該字存在
 * startsWith 跟 search 一樣，但不需要 endOfWord，能找完就直接回傳 true
 * 時間: insert: O(n), search: O(n), startsWith: O(n), 空間: O(n*m), n: 最長的字
 * 長; m: 字的數量
 */

class Trie
{
  public:
    Trie() : endOfWord(false)
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }

    void insert(string word)
    {
        Trie *current = this;
        int index = 0;
        for (int i = 0; i < word.length(); i++)
        {
            index = word[i] - 'a';
            if (current->children[index] == nullptr)
            {
                current->children[index] = new Trie();
            }
            current = current->children[index];
        }
        current->endOfWord = true;
    }

    bool search(string word)
    {
        Trie *current = this;
        int index = 0;
        for (int i = 0; i < word.length(); i++)
        {
            index = word[i] - 'a';
            if (current->children[index] == nullptr)
            {
                return false;
            }
            current = current->children[index];
        }
        return current->endOfWord;
    }

    bool startsWith(string prefix)
    {
        Trie *current = this;
        int index = 0;
        for (int i = 0; i < prefix.length(); i++)
        {
            index = prefix[i] - 'a';
            if (current->children[index] == nullptr)
            {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }

  private:
    Trie *children[26];
    bool endOfWord;
};