class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        /*
            我的方法
            時間複雜度O(n)、空間複雜度O(1)(題目說字元固定為a~z，最多為26個)
            利用unordered_map紀錄字元在ransomNote及magazine中出現的次數，
            如果ransomeNote出現次數比magazine多，就回傳false
        */

        unordered_map<char, pair<int, int>> appears;

        for (int i = 0; i < magazine.length(); i++)
        {
            appears[magazine[i]].first++;
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {
            appears[ransomNote[i]].second++;
        }

        for (auto &it : appears)
        {
            if (it.second.second > it.second.first)
            {
                return false;
            }
        }

        return true;
    }
};