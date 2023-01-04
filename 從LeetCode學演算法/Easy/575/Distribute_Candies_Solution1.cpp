class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        /*
            我的方法
            時間複雜度O(n)、空間複雜度O(n)
            將所有種類存到unordered_set，再取一半
        */

        unordered_set<int> types;
        int maxSize = candyType.size() / 2;
        int counter = 0;

        for (int i = 0; i < candyType.size(); i++)
        {
            if (types.count(candyType[i]) == 0)
            {
                types.insert(candyType[i]);
            }
        }

        for (auto &it : types)
        {
            if (maxSize > 0)
            {
                maxSize--;
                counter++;
            }
        }

        return counter;
    }
};