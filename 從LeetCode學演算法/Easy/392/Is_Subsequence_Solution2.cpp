class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        /*
            參考的方法
            時間複雜度O(length of t + length of s)、空間複雜度O(length of t)
            先用map紀錄t中每個字元對應的出現位置，再透過set找lower_bound(第一個出現s[i]的位置)
        */

        unordered_map<char, set<int>> indices;

        for (int i = 0; i < t.length(); i++)
        {
            indices[t[i]].insert(i);
        }

        int previousIndex = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (indices.find(s[i]) == indices.end())
            {
                return false;
            }
            else
            {
                auto firstIndex = indices[s[i]].lower_bound(previousIndex);
                if (firstIndex == indices[s[i]].end())
                {
                    return false;
                }
                else
                {
                    previousIndex = *firstIndex + 1;
                }
            }
        }

        return true;
    }
};