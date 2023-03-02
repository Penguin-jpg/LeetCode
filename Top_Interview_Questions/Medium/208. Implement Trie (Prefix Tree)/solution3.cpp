#include <memory>
#include <string>
using namespace std;

/**
 * 參考解答: 或者直接用 c++ 的 smart pointer，讓它處理自己處理回收問題
 * 時間: insert: O(n), search: O(n), startsWith: O(n), 空間: O(n*m), n: 最長的字
 * 長; m: 字的數量
 */

class TrieNode
{
  public:
    TrieNode() : endOfWord(false)
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
    unique_ptr<TrieNode> children[26];
    bool endOfWord;
};

class Trie
{
  public:
    Trie()
    {
        root = make_unique<TrieNode>();
    }

    void insert(string word)
    {
        TrieNode *current = root.get(); // get the pointer of root
        int index = 0;
        for (int i = 0; i < word.length(); i++)
        {
            index = word[i] - 'a';
            if (current->children[index] == nullptr)
            {
                current->children[index] = make_unique<TrieNode>();
            }
            current = current->children[index].get();
        }
        current->endOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *current = root.get();
        int index = 0;
        for (int i = 0; i < word.length(); i++)
        {
            index = word[i] - 'a';
            if (current->children[index] == nullptr)
            {
                return false;
            }
            current = current->children[index].get();
        }
        return current->endOfWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *current = root.get();
        int index = 0;
        for (int i = 0; i < prefix.length(); i++)
        {
            index = prefix[i] - 'a';
            if (current->children[index] == nullptr)
            {
                return false;
            }
            current = current->children[index].get();
        }
        return true;
    }

  private:
    unique_ptr<TrieNode> root;
};