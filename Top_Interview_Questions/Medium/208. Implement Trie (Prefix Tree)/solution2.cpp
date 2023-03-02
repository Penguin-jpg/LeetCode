#include <string>
using namespace std;

/**
 * 參考解答: 如果用 c++ 的話最好是考慮 memory leak 的問題，也就是要記得建立
 * destructor 把用完的 Trie 砍掉，避免那部分的記憶體外洩 (由於我直接寫在 Trie 內
 * 的方式不太適合用 destructor，所以會多用一個 TrieNode class 去紀錄 Trie 的東西)
 * 時間: insert: O(n), search: O(n), startsWith: O(n), 空間: O(n)
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
    TrieNode *children[26];
    bool endOfWord;
};

class Trie
{
  public:
    Trie()
    {
        root = new TrieNode();
    }

    ~Trie()
    {
        clear(root);
    }

    void insert(string word)
    {
        TrieNode *current = root;
        int index = 0;
        for (int i = 0; i < word.length(); i++)
        {
            index = word[i] - 'a';
            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->endOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *current = root;
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
        TrieNode *current = root;
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

    void clear(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != nullptr)
            {
                clear(root->children[i]);
            }
        }
        delete root;
    }

  private:
    TrieNode *root;
};