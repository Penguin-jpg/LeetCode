class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        /*
            時間複雜度O(n)、空間複雜度O(1)
            用sliding window的方式做，
            慢慢將該window把整個s字串掃完
        */

        if (p.length() > s.length())
        {
            return vector<int>();
        }

        vector<int> indices;
        unordered_map<char, int> counter;
        int left = 0;
        int right = 0;
        int count = p.length();

        for (int i = 0; i < p.length(); i++)
        {
            counter[p[i]]++;
        }

        while (right < s.length())
        {
            //window往右移動一格(擴展window)
            if (counter[s[right++]]-- > 0)
            {
                count--;
            }

            //如果counter為0，代表符合的字都找到了
            if (count == 0)
            {
                indices.push_back(left);
            }

            //window左邊的範圍往右移動一格
            if (right - left == p.length() && counter[s[left++]]++ >= 0)
            {
                count++;
            }
        }

        return indices;
    }
};