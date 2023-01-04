class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(1)
            由於題目限定字元為a~z，可以直接使用大小為26的陣列處理
        */

        vector<int> nums(26, 0);

        for (int i = 0; i < magazine.length(); i++)
        {
            nums[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {
            if (nums[ransomNote[i] - 'a'] - 1 < 0)
            {
                return false;
            }

            nums[ransomNote[i] - 'a']--;
        }

        return true;
    }
};