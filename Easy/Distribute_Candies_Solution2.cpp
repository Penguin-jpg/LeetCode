class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(n)
            將每個種類的數量用unordered_map存起來，算出有多少種類，
            如果算出的數字和所有種類的一半一樣或更少，就代表只能拿這麼多種類，
            如果算出的數字比所有種類的一半還多，就代表最多只能拿一半
        */

        unordered_map<int, int> types;
        int counter = 0;

        for (int i = 0; i < candyType.size(); i++)
        {
            types[candyType[i]]++;

            if (types[candyType[i]] == 1)
            {
                counter++;
            }
        }

        return counter <= candyType.size() / 2 ? counter : candyType.size() / 2;
    }
};